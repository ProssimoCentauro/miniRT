#include "minirt.h"

/*
 * apply_lighting:
 * Calcola l'illuminazione finale su un punto colpito da un raggio,
 * tenendo conto della luce ambientale e delle luci puntiformi presenti nella scena.
 *
 * Parametri:
 *   - scene: puntatore alla struttura che contiene luci e luce ambientale.
 *   - hit:   puntatore alla struttura con le informazioni del punto colpito.
 *
 * Funzionamento:
 * 1. Inizializza il colore finale (result) a nero.
 * 2. Aggiunge il contributo della luce ambientale:
 *      - Moltiplica il colore dell'oggetto per il ratio della luce ambientale
 *        e per il colore della luce ambientale normalizzato ([0,1]).
 * 3. Per ogni luce puntiforme nella scena:
 *      - Calcola il vettore direzione dalla luce al punto colpito.
 *      - Normalizza la direzione e calcola il prodotto scalare con la normale.
 *      - Applica il modello di illuminazione diffusa (Lambert):
 *          -> diff = max(0, dot(normal, light_dir))
 *          -> il colore della luce è proporzionale a diff, alla luminosità della luce
 *             e al colore della luce.
 *      - Somma questo contributo al colore finale.
 * 4. Esegue il clamping dei valori RGB a massimo 255 per evitare overflow.
 * 5. Restituisce il colore risultante.
 *
 * Nota: non tiene conto di ombre, riflessi o specularità (solo diffusa + ambient).
 */


t_rgb apply_lighting(t_scene *scene, t_hit *hit)
{
	t_rgb result = {{0, 0, 0, 100}};
	t_light *light = scene->lights;
	t_vector	light_dir;
	double diff;

	// Ambient light
	result.r += hit->rgb.r * scene->amb->ratio * (scene->amb->rgb.r / 255.0);
	result.g += hit->rgb.g * scene->amb->ratio * (scene->amb->rgb.g / 255.0);
	result.b += hit->rgb.b * scene->amb->ratio * (scene->amb->rgb.b / 255.0);

	while (light)
	{
		light_dir = vector_normalize(vector_sub(light->coord, hit->point));
		diff = fmax(0.0, vector_dot(hit->normal, light_dir));

		result.r += hit->rgb.r * diff * light->brightness * (light->rgb.r / 255.0);
		result.g += hit->rgb.g * diff * light->brightness * (light->rgb.g / 255.0);
		result.b += hit->rgb.b * diff * light->brightness * (light->rgb.b / 255.0);
		light = light->next;
	}

	// Clamp to [0, 255]
	result.r = fmin(result.r, 255);
	result.g = fmin(result.g, 255);
	result.b = fmin(result.b, 255);
	return result;
}

