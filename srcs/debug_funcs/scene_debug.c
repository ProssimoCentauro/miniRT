#include "minirt.h"

static const char *type_to_string(t_type type)
{
    switch(type)
    {
        case A_LIGHT: return "Ambient Light";
        case CAMERA: return "Camera";
        case LIGHT: return "Light";
        case SPHERE: return "Sphere";
        case PLANE: return "Plane";
        case CYLINDER: return "Cylinder";
        case CONE: return "Cone";
        case TRIANGLE: return "Triangle";
        default: return "Unknown";
    }
}

static void print_rgb(t_rgb rgb)
{
    printf("R: %d G: %d B: %d", rgb.r, rgb.g, rgb.b);
}

static void print_vector(t_vector v)
{
    printf("(%.2f, %.2f, %.2f)", v.x, v.y, v.z);
}

static void print_object(t_object *obj)
{
    if (!obj) return;

    printf(BOLD_YELLOW "Object type: %s\n" RESET, type_to_string(obj->type));
    switch (obj->type)
    {
        case SPHERE:
            printf("  Coord: ");
            print_vector(obj->figure.sphere.coord);
            printf("\n  Diameter: %.2f\n  Color: ", obj->figure.sphere.diameter);
            print_rgb(obj->figure.sphere.rgb);
            printf("\n");
            break;
        case PLANE:
            printf("  Coord: ");
            print_vector(obj->figure.plane.coord);
            printf("\n  Normal: ");
            print_vector(obj->figure.plane.normal);
            printf("\n  Color: ");
            print_rgb(obj->figure.plane.rgb);
            printf("\n");
            break;
        case CYLINDER:
            printf("  Coord: ");
            print_vector(obj->figure.cylinder.coord);
            printf("\n  Normal: ");
            print_vector(obj->figure.cylinder.normal);
            printf("\n  Diameter: %.2f\n  Height: %.2f\n  Color: ", 
                obj->figure.cylinder.diameter, obj->figure.cylinder.height);
            print_rgb(obj->figure.cylinder.rgb);
            printf("\n");
            break;
        default:
            printf("  [No detailed printer implemented]\n");
            break;
    }
}

void print_scene(t_scene *scene)
{
    if (!scene) return;

    // Camera
    printf(BOLD_CYAN "=== Camera ===\n" RESET);
    printf("Coord: ");
    print_vector(scene->cam->coord);
    printf("\nOrientation: ");
    print_vector(scene->cam->orientation);
    printf("\nFOV: %.2f\n\n", scene->cam->fov); 

    // Ambient Light
    printf(BOLD_MAGENTA "=== Ambient Light ===\n" RESET);
    printf("Ratio: %.2f\nColor: ", scene->amb->ratio);
    print_rgb(scene->amb->rgb);
    printf("\n\n");

    // Lights (linked list)
    printf(BOLD_GREEN "=== Lights ===\n" RESET);
    t_light *light = scene->lights;
    int i = 0;
    while (light)
    {
        printf("Light %d:\n", i);
        printf("  Coord: ");
        print_vector(light->coord);
        printf("\n  Brightness: %.2f\n  Color: ", light->brightness);
        print_rgb(light->rgb);
        printf("\n\n");
        light = light->next;
        i++;
    }

    // Objects (linked list)
    printf(BOLD_YELLOW "=== Objects ===\n" RESET);
    t_object *obj = scene->objs;
    i = 0;
    while (obj)
    {
        printf("Object %d:\n", i);
        print_object(obj);
        printf("\n");
        obj = obj->next;
        i++;
    }
}

