//
//  function.h
//  13787 - Pokemon Battle Manager
//
//  Created by Brian on 2022/12/25.
//

#ifndef function_h
#define function_h

#include <stdio.h>
#define lvup_atk 200
#define lvup_dfn 100
#define lvup_maxHp 20
#define lvup_maxMp 15
#define T 2

typedef struct pokemon{
    int id;
    char name[10];
    int level;
    int attack;
    int defense;
    int Hp;
    int Mp;
    int maxHp;
    int maxMp;
    int costMp;
}Pokemon;

// TODO: upgrade and recover the Pokémon
void level_up(Pokemon *P);

// TODO: simulate and print the process of the battle
void battle(Pokemon *A, Pokemon *B);

#endif /* function_h */
