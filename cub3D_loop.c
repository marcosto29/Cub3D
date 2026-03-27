/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:14:22 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/26 19:49:30 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	cub3D_loop(char **worldMap)
{
	int	i;
	
	while(1)
	{
		i = 0;
		t_vector	*ray;
		t_vector	*dist_ray_wall;
		t_vector	*step;
		t_vector	*dist;
		double		cameraX;

		ray = malloc(sizeof(t_vector));
		step = malloc(sizeof(t_vector));
		dist_ray_wall = malloc(sizeof(t_vector));
		dist = malloc(sizeof(t_vector));
		//disparamos un rayo para pixel de la pantalla y lo transformamos a coordenadas del plano
		//esta transformación se hace a partir de la fórmula:
		//rayo = dirección_rayo + plano * posición_relativa
		//donde la posición_relativa es la coordenada horizontal de la pantalla transformada al plano, la coordenada relativa
		//es decir, si el pixel es el 100 y la pantalla son 400 pixeles, la posición del pixel 100 en el plano camara será
		//posición_relativa = 2 * x / W - 1
		//2 * 100 / 400 - 1 = -0.5, es decir en la izquierda mitad
		// -------------------|--------------------
		//         ^
		//		   | aquí
		//el rayo entonces quedará tal que
		// x = -1 + 0 * -0.5 = -1
		// y = 0 + 0.66 * -0.5 = -0.33
		//rayo = (-1, -0.33)
		//hacemos este cálculo para cada pixel horizontal (no es para cada pixel de la pantalla sino para cada columan de píxeles en la posición 0)
		//0, 1, 2 ..... 400
		//|  |  |        |
		//|  |  |        |
		//|  |  |        |
		//|  |  |        |
		//|  |  |        |
		while (i < SCREEN_WIDTH)
		{
			cameraX = 2 * i / (double)SCREEN_WIDTH - 1;
			ray->x = player(NULL)->direction->x + (player(NULL)->camera_plane->x * cameraX);
			ray->y = player(NULL)->direction->y + (player(NULL)->camera_plane->y * cameraX);
			//una vez tenemos el rayo trabajamos bajo un mapa rectangular del que vamos a ir cuadrado a cuadrrado comprobando si hay un muro
			//para avanazar se hace paso a paso recorriendo el rayo comprobando el choque con los respectivos ejes de la cuadrícula
			//en el caso del eje de las y habría que dar un paso horizontalmente para llegar al siguiente choque y lo mismo para el de las X
			//     0   1
			//-----|---|-/--- 0 choque en el eje x después de dar un paso vertical
			//     |   |/
			//     |   | <---- choque en el eje y después de dar un paso horizontal
			//     |  /|
			//     | / |
			//-----|/--|------ 1
			//para saber la distancia se hace pitágoras donde sabemos que uno de los lados tiene que ser 1
			//y el otro por como funcionan los vectores será la pendiente y/x
			//¿por qué?: porque un vector no es nada más que una deficinición de movimiento un vector x=2, y=1 solo nos dice que por cada 2 movimientos en X se hace 1 en Y
			//por lo tanto para sabr cuantos movmimientos se requieren en y para hacer 1 solo en X se hace una división tal que: x=X/X, y=Y/X -> x=2/2, y=1/2 -> x=1, y=0.5
			//es decir, en resumen los catetos serán por ejemplo para la distancia hasta el siguiente choque de y: X=X/X Y=Y/X
			//y la hipotenusa es h^2 = c1^2 + c2^2 -> (X/X)^2 + (Y/X)^2
			//o por otro lado h = raiz cuadarada de ((X/X)^2 + (Y/X)^2)
			//se que esto se puede simplificar, no se como ahora.
			//TODO: gestionar si rayX o rayY es 0 para que no pete
			dist_ray_wall->x = sqrt(1 + pow((ray->y/ray->x), 2));
			dist_ray_wall->y = sqrt(pow((ray->x/ray->y), 2) + 1);
			//con estas distancias podemos movernos entre los cuadrados para ver cual es una pared y cuál no
			//para poder, sin embargo movernos entre estos cuadrados primero es necesario encontrar el primer choque con los ejes para poder aplicar esta lógica
			//y saber la dirección en la que mirar
			//     |      |/ -> primer golpe eje y, a partir de aquí se puede usar la distRayWallY para el siguiente
			//-----|------|  -> primer golpe eje x, a partir de aquí se puede usar la distRayWallX para el siguiente
			//     |     /|
			//     |    / |
			//     |   o  |
			//-----|--/---|-
			//para comprobar la dirección en la que mirar es necesario comprobar el signo del rayo de dirección.
			//si el rayX es negativo se irá hacia atrás en X, si es positivo se irá hacia delante, lo mismo para rayY
			step->x = 1;
			step->y = 1;
			//el primer paso para llegar hasta el muro más cercano se hace a partir de la posición de jugador y las coordenadas de casillas más cercanas que tenga (convirtiendo el double a int)
			//en función de la dirección del rayo se querrá encontrar
			//el eje más cercano de la izquierda o abajo (si la dirección es negativa) o
			//el eje más cercano de la derecha o arriba (si la dirección es positiva)
			//esto se hace fácilmente primero calculando cuanto queda hasta el siguiente cubo restando la posición del jugador a la más cercana (sun int)
			//ejemplo, el jugador está en 3.7 y quiere llegar a 3 -> 3.7 - 3 = 0.7 (le queda el 70%)
			//y ese porcentaje se le aplica a la distancia previamente calculada -> distRayWallX * 0.7 (el 70% de l distancia al siguiente punto)
			//si es positivo y el jugador quiere llegar a 4 se hará al revés tal que
			//(3 + 1) - 3.7 = 0.3, se redondea al integer y se le suma 1 quedando el 30% restante.
			int	mapX = (int)player(NULL)->position->x;
			int	mapY = (int)player(NULL)->position->y;
			if (ray->x < 0)
			{
				step->x *= -1;
				dist->x = (player(NULL)->position->x - mapX) * dist_ray_wall->x;
			}
			else
				dist->x = (mapX + 1 - player(NULL)->position->x) * dist_ray_wall->x;
			if (ray->y < 0)
			{
				step->y *= -1;
				dist->y = (player(NULL)->position->y - mapY) * dist_ray_wall->y;
			}
			else
				dist->y = (mapY + 1 - player(NULL)->position->y) * dist_ray_wall->y;
			//Otro factor a tener en cuenta es comprbar si se ha golpeado a la pared por norte sur este u oeste
			int	side;
			int hit = 0;
			//en un bucle se va avanzando horizontal y verticlamente paso a paso hasta encontrar un hit con una pared
			while (hit == 0)
			{
				if (dist->y < dist->x)
				{
					dist->y += dist_ray_wall->y;
					mapY += step->y;
					side = 0;
				}
				else
				{
					dist->x += dist_ray_wall->x;
					mapX += step->x;
					side = 1;
				}
				if (worldMap[mapX][mapY] - '0' > 0) 
					hit = 1;
			}
			i++;
			(void)side;
		}
		mlx_loop(screen()->mlx);
	}
}
