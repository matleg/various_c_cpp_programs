
// from https://stackoverflow.com/questions/327893/how-to-write-a-compare-function-for-qsort-from-stdlib

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct entity
{
    int x;
    int y;
    int velocity;
    int mass;
};

typedef struct entity Entity;

int sort_function(const void *p_a, const void *p_b)
{
    /* Need to store arguments in appropriate type before using */
    const Entity *ent_a = p_a;
    const Entity *ent_b = p_b;

    if (ent_a->velocity > ent_b->velocity)
        return 1;
    if (ent_a->velocity < ent_b->velocity)
        return -1;

    /* If velocities are equal return 1 or -1 if mass not equal */
    if (ent_a->mass > ent_b->mass)
        return 1;
    if (ent_a->mass < ent_b->mass)
        return -1;

    /* Return 0 if both members are equal in both structures */
    return 0;
}

int main()

{

    // table of entities:
    Entity entities[4];
    entities[0].velocity = 4;
    entities[0].mass = 2;
    printf("%i \n", entities[0].velocity);

    entities[1].velocity = 4;
    entities[1].mass = 5;

    entities[2].velocity = 10;
    entities[2].mass = 2;

    entities[3].velocity = 1;
    entities[3].mass = 2;

    printf("before\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ( %d , %d )\n", i, entities[i].velocity, entities[i].mass);
    };

    qsort(&entities, 4, sizeof(Entity), sort_function);

    printf("\nafter\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ( %d , %d )\n", i, entities[i].velocity, entities[i].mass);
    };
}
