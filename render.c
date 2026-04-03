/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:14:22 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/03 21:28:47 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wall_color(int wall)
{
	if (wall == 1)
		return (0xFF0000);
	if (wall == 2)
		return (0x00FF00);
	if (wall == 3)
		return (0x0000FF);
	if (wall == 4)
		return (0xFF00FF);
	return (0);
}

int	paint_pixels(int pixel_column, t_vector pixels_bound, void *img, int wall)
{
	t_image_data	image_data;
	char			*image_aux;
	int				i;
	int				memory_space;

	image_data.image = mlx_get_data_addr(img, &image_data.bits_per_pixel,
			&image_data.line_size, &image_data.endian);
	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		if (i >= pixels_bound.x && i <= pixels_bound.y)
		{
			//nos vamos desplazando por el array de caracteres que representa la imagen
			//moviendonos de 4 en 4 (los bytes que sirven para representar el color de cada pixel)
			memory_space = i * image_data.line_size + pixel_column * 4;
			image_aux = image_data.image + memory_space;
			*(unsigned int *)image_aux = mlx_get_color_value(screen()->mlx, wall_color(wall));
		}
		i++;
	}
	return (0);
}


void	draw_image()
{
	int			i;
	t_vector	ray;
	t_vector	dist_ray_wall;
	t_vector	step;
	t_vector	dist;
	double		camera_x;

	i = 0;
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
	//Creamos la imagen que vamos a rellenar
	if (screen()->img)
		mlx_destroy_image(screen()->mlx, screen()->img);
	screen()->img = mlx_new_image(screen()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	while (i < SCREEN_WIDTH)
	{
		camera_x = 2 * i / (double)SCREEN_WIDTH - 1;
		ray.x = player(NULL)->direction.x + (player(NULL)->camera_plane.x * camera_x);
		ray.y = player(NULL)->direction.y + (player(NULL)->camera_plane.y * camera_x);
		//una vez tenemos el rayo trabajamos bajo un mapa rectangular del que vamos a ir cuadrado a cuadrado comprobando si hay un muro
		//para avanazar se hace paso a paso recorriendo el rayo comprobando el choque con los respectivos ejes de la cuadrícula
		//en el caso del eje de las y habría que dar un paso horizontalmente para llegar al siguiente choque y lo mismo para el de las X
		//     0   1
		//-----|---|-/--- 0 choque en el eje x después de dar un paso vertical
		//     |   |/
		//     |   | <---- choque en el eje y después de dar un paso horizontal
		//     |  /|
		//     | / |
		//-----|/--|------ 1
		//*********************GEOMETRÍA PITÁGORAS**************************
		//para saber la distancia se hace pitágoras donde sabemos que uno de los lados tiene que ser 1
		//y el otro por como funcionan los vectores será la pendiente y/x
		//¿por qué?: porque un vector no es nada más que una deficinición de movimiento un vector x=2, y=1 solo nos dice que por cada 2 movimientos en X se hace 1 en Y
		//por lo tanto para sabr cuantos movmimientos se requieren en y para hacer 1 solo en X se hace una división tal que: x=X/X, y=Y/X -> x=2/2, y=1/2 -> x=1, y=0.5
		//es decir, en resumen los catetos serán por ejemplo para la distancia hasta el siguiente choque de y: X=X/X Y=Y/X
		//y la hipotenusa es h^2 = c1^2 + c2^2 -> (X/X)^2 + (Y/X)^2
		//o por otro lado h = raiz cuadarada de ((X/X)^2 + (Y/X)^2)
		//**********SIMPLIFICADO GEOMETRÍA OPERACIÓN VECTORES***************
		//para calcular la posición en la que se encontrará el jugador después de avanzar cierto espacio
		//PosiciónNueva = posX + rayDirX * distancia
		//entonces PosiciónNueva = posicionJugador + rayDir * distancia
		//distancia = (PosiciónNueva - posiciónJugador) / rayDir
		//si queremos avanzar el doble de eso
		//PosiciónNueva = posX + rayDirX * distancia
		//entonces PosiciónNueva + 1 = posicionJugador + rayDir * distancia2
		//distancia2 = (PosiciónNueva + 1 - posiciónJugador) / rayDir
		//por lo tanto ya que distancia2 - distancia es la longitud entre las celdas
		//longitud = [(PosiciónNueva + 1 - posiciónJugador) / rayDir] - [(PosiciónNueva - posiciónJugador) / rayDir]
		//longitud = (PosiciónNueva + 1 - posiciónJugador - PosiciónNueva + posiciónJugador) / rayDir
		//longitud = (1 / rayDir)
		//y como es una distancia nos quedamos con el valor absoluto
		//longitud = abs(1 / rayDir)
		//TODO: GESTIONAR CASO 0
		dist_ray_wall.x = fabs(1 / ray.x);
		dist_ray_wall.y = fabs(1 / ray.y);
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
		step.x = 1;
		step.y = 1;
		//el primer paso para llegar hasta el muro más cercano se hace a partir de la posición de jugador y las coordenadas de casillas más cercanas que tenga (convirtiendo el double a int)
		//en función de la dirección del rayo se querrá encontrar
		//el eje más cercano de la izquierda o abajo (si la dirección es negativa) o
		//el eje más cercano de la derecha o arriba (si la dirección es positiva)
		//esto se hace fácilmente primero calculando cuanto queda hasta el siguiente cubo restando la posición del jugador a la más cercana (sun int)
		//ejemplo, el jugador está en 3.7 y quiere llegar a 3 -> 3.7 - 3 = 0.7 (le queda el 70%)
		//y ese porcentaje se le aplica a la distancia previamente calculada -> distRayWallX * 0.7 (el 70% de l distancia al siguiente punto)
		//si es positivo y el jugador quiere llegar a 4 se hará al revés tal que
		//(3 + 1) - 3.7 = 0.3, se redondea al integer y se le suma 1 quedando el 30% restante.
		int	map_x = (int)player(NULL)->position.x;
		int	map_y = (int)player(NULL)->position.y;
		if (ray.x < 0)
		{
			step.x *= -1;
			dist.x = (player(NULL)->position.x - map_x) * dist_ray_wall.x;
		}
		else
			dist.x = (map_x + 1 - player(NULL)->position.x) * dist_ray_wall.x;
		if (ray.y < 0)
		{
			step.y *= -1;
			dist.y = (player(NULL)->position.y - map_y) * dist_ray_wall.y;
		}
		else
			dist.y = (map_y + 1 - player(NULL)->position.y) * dist_ray_wall.y;
		//Otro factor a tener en cuenta es comprbar si se ha golpeado a la pared por norte/sur o este/oeste
		int	side;
		int hit = 0;
		//en un bucle se va avanzando horizontal y verticlamente paso a paso hasta encontrar un hit con una pared
		while (hit == 0)
		{
			if (dist.y < dist.x)
			{
				dist.y += dist_ray_wall.y;
				map_y += step.y;
				//golpeo pared vertical
				side = 0;
			}
			else
			{
				dist.x += dist_ray_wall.x;
				map_x += step.x;
				//golpeó pared horizontal
				side = 1;
			}
			if (world_map(NULL)[map_x][map_y] - '0' > 0) 
				hit = 1;
		}
		//una vez se sabe el elemento que ha sido golpeado, se tiene que cacular su distancia al plano de renderizado para poder pintarlo con la altura correcta en pantalla
		//para calcular la distancia al plano, no se coje la distancia al punto del jugador.
		//ya que intentar renderizar todo desde un punto daría una sensación de vista de pez
		//   o           o       
		//    \         /
		//     \       /
		//      \     /
		//       \   /
		//        \ /
		//         o
		//lo que se hace es usar el plano camara como sitio de renderizado haciendo que todo esté recto
		//simulando mejor una pantalla
		//   o           o
		//   |           |
		//   |           |
		//   |           |
		//   |           |
		//   |           |
		//---------o---------
		//para poder calcular la distancia del punto golpeado al plano se tiene que hacer una perpendicular al plano camara (paralela al rayo de dirección)
		//desde el punto al propio plano
		//   o           o       
		//   |\         /|
		//   | \       / |
		//   |  \     /  |
		//   |   \   /   |
		//   |    \ /    |
		//---------o---------
		//por la naturaleza del algoritmo si se quisiera saber solo la distancia al jugador dependería de la última pared golpeada
		//DISTANCIA AL JUGADOR NO AL PLANO
		//TODO: HACERLA AL PLANO
		double		wall_hitted_distance;
		if (side == 0)
			wall_hitted_distance = dist.y - dist_ray_wall.y;
		else
			wall_hitted_distance = dist.x - dist_ray_wall.x;
		//esto es así ya que el algoritmo primero avanza a la siguiente colisión y luego comprueba si la anterior era un muro
		//con la distancia se puede calcular cual va a ser la altura en la camara, por qué
		//se tiene que establecer una altura real y una relación altura distancia que tenga sentido
		//si por ejemplo decimos que la altura real del cubo son 200
		//a una distancia de 0 la altura será 200 pero cuanto más andemos más pequeño se verá (una relacón inversa), es decir
		//la altura en camara será igual a 1 / distancia * la altura real o altura real / distancia
		double height;
		double realHeight = SCREEN_HEIGHT / 2;
		height =  realHeight / wall_hitted_distance;
		//y desde donde pintarlo y hasta donde pintarlo se calcula teniendo en cuenta que el centro de la pared tiene que estar en la mitad del eje y
		t_vector	pixel_bound;
		pixel_bound.x = SCREEN_HEIGHT / 2 - height / 2;
		if (pixel_bound.x < 0)
			pixel_bound.x = 0;
		pixel_bound.y = SCREEN_HEIGHT / 2 + height / 2;
		if (pixel_bound.y > SCREEN_HEIGHT - 1)
			pixel_bound.y = SCREEN_HEIGHT - 1;
		//teniendo el pixel ya desde donde empieza a dibujar hasta donde acaba, se llaman a las funciones de la librería y se renderizan
		paint_pixels(i, pixel_bound, screen()->img, world_map(NULL)[map_x][map_y] - '0');
		i++;
	}
	mlx_put_image_to_window(screen()->mlx, screen()->win, screen()->img, 0, 0);
}
