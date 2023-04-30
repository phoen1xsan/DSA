// // // #include <stdio.h>
// // // #include <conio.h>
// // // #define SIZE 10 
// // // #define FALSE 0
// // // #define TRUE 1
// // // #define h(x) x % SIZE 
// // // void insert(int data[], int flag[], int chain[], int x);
// // // int search(int data[], int flag[], int chain[], int x);
// // // void print(int data[], int flag[], int chain[]);

// // // void main(){
// // //     int data[SIZE], flag[SIZE], chain[SIZE], i, j, x, op, loc;
// // //     for (i = 0; i < SIZE; i++){
// // //         flag[i] = FALSE;
// // //         chain[i] = -1;
// // //     }

// // //     do{

// // //         printf("\n\n1)Insert\n2)Search\n3)Print\n4)Quit");
// // //         printf("\nEnter Your Choice : ");
// // //         scanf("%d", &op);
// // //         switch (op){
// // //         case 1:
// // //             printf("\n Enter a number to be inserted:");
// // //             scanf("%d", &x);
// // //             insert(data, flag, chain, x);
// // //             break;
// // //         case 2:
// // //             printf("\n Enter a number to be searched :");
// // //             scanf("%d", &x);
// // //             if ((loc = search(data, flag, chain, x)) == -1)
// // //                 printf("\n***Element not found***");
// // //             else
// // //                 printf("\n***Found at the location=%d", loc);
// // //             break;
// // //         case 3:
// // //             print(data, flag, chain);
// // //             break;
// // //         }
// // //     } 
// // //     while (op != 4);
// // // }

// // // void insert(int data[], int flag[], int chain[], int x){
// // //     int i = 0, j, start;
// // //     start = h(x);
// // //     while (flag[start] && i < SIZE){
// // //         if (data[start] % SIZE == x % SIZE)
// // //             break;
// // //         i++;
// // //         start = (start + 1) % SIZE;
// // //     }
// // //     if (i == SIZE){
// // //         printf("\n**hash table is full***");
// // //         return;
// // //     }
// // //     while (chain[start] != -1)
// // //         start = chain[start];
// // //     j = start;
// // //     while (flag[j] && i < SIZE){
// // //         j = (j + 1) % SIZE;
// // //         i = i + 1;
// // //     }
// // //     if (i == SIZE)
// // //     {
// // //         printf("\n**hash table is full***");
// // //         return;
// // //     }
// // //     data[j] = x;
// // //     flag[j] = TRUE;
// // //     if (j != start)
// // //         chain[start] = j; 
// // // }

// // // int search(int data[], int flag[], int chain[], int x){
// // //     int i = 0, j;
// // //     j = h(x);
// // //     while (i < SIZE && flag[j] && data[j] % SIZE != x % SIZE){
// // //         i++;
// // //         j = (j + 1) % SIZE;
// // //     }
// // //     if (!flag[j] || i == SIZE)
// // //         return (-1);
// // //     while (j != -1)
// // //     {
// // //         if (data[j] == x)
// // //             return (j);
// // //         j = chain[j];
// // //     }
// // //     return (-1);
// // // }

// // // void print(int data[], int flag[], int chain[]){
// // //     int i;
// // //     for (i = 0; i < SIZE; i++)
// // //         if (flag[i])
// // //             printf("\n(%d) %d     %d", i, data[i], chain[i]);
// // //         else
// // //             printf("\n(%d) ---    %d", i, chain[i]);
// // // }




#include <stdio.h>
#include <conio.h>
#define SIZE 8 
#define FALSE 0
#define TRUE 1
#define h(x) x % SIZE 
void insert(int data[], int flag[], int chain[], int x);
int search(int data[], int flag[], int chain[], int x);
void print(int data[], int flag[], int chain[]);

void main(){
    int data[SIZE], flag[SIZE], chain[SIZE], i, j, x, loc;
    for (i = 0; i < SIZE; i++){
        flag[i] = FALSE;
        chain[i] = -1;
    }

    printf("\nEnter %d numbers to be inserted:", SIZE);
    for (i = 0; i < SIZE; i++){
        scanf("%d", &x);
        insert(data, flag, chain, x);
    }

    printf("\nHash Table Contents:");
    print(data, flag, chain);

    printf("\n\nSearch Results:\n");
    for (i = 0; i < SIZE; i++){
        printf("Enter a number to be searched: ");
        scanf("%d", &x);
        loc = search(data, flag, chain, x);
        if (loc == -1)
            printf("***Element %d not found***\n", x);
        else
            printf("***Found %d at location %d***\n", x, loc);
    }
}


void insert(int data[], int flag[], int chain[], int x){
    int i = 0, j, start;
    start = h(x);
    while (flag[start] && i < SIZE){
        if (data[start] % SIZE == x % SIZE)
            break;
        i++;
        start = (start + 1) % SIZE;
    }
    if (i == SIZE){
        printf("\n**hash table is full***");
        return;
    }
    while (chain[start] != -1)
        start = chain[start];
    j = start;
    while (flag[j] && i < SIZE){
        j = (j + 1) % SIZE;
        i = i + 1;
    }
    if (i == SIZE)
    {
        printf("\n**hash table is full***");
        return;
    }
    data[j] = x;
    flag[j] = TRUE;
    if (j != start)
        chain[start] = j; 
}

int search(int data[], int flag[], int chain[], int x){
    int i = 0, j;
    j = h(x);
    while (i < SIZE && flag[j] && data[j] % SIZE != x % SIZE){
        i++;
        j = (j + 1) % SIZE;
    }
    if (!flag[j] || i == SIZE)
        return (-1);
    while (j != -1)
    {
        if (data[j] == x)
            return (j);
        j = chain[j];
    }
    return (-1);
}

void print(int data[], int flag[], int chain[]){
    int i;
    for (i = 0; i < SIZE; i++)
        if (flag[i])
            printf("\n(%d) %d     %d", i, data[i], chain[i]);
        else
            printf("\n(%d) ---    %d", i, chain[i]);
}



// #include <stdio.h>
// #include <conio.h>
// #define SIZE 10 
// #define FALSE 0
// #define TRUE 1
// #define h(x) x % SIZE 
// void insert(int data[], int flag[], int chain[], int x);
// int search(int data[], int flag[], int chain[], int x);
// void print(int data[], int flag[], int chain[]);

// void main(){
//     int data[SIZE], flag[SIZE], chain[SIZE], i, j, x, loc, num_inputs;
//     for (i = 0; i < SIZE; i++){
//         flag[i] = FALSE;
//         chain[i] = -1;
//     }

//     printf("\nEnter the number of inputs (up to %d): ", SIZE);
//     scanf("%d", &num_inputs);

//     printf("\nEnter %d numbers to be inserted:", num_inputs);
//     for (i = 0; i < num_inputs; i++){
//         scanf("%d", &x);
//         insert(data, flag, chain, x);
//     }

//     printf("\nHash Table Contents:");
//     print(data, flag, chain);

//     printf("\n\nSearch Results:\n");
//     for (i = 0; i < num_inputs; i++){
//         printf("Enter a number to be searched: ");
//         scanf("%d", &x);
//         loc = search(data, flag, chain, x);
//         if (loc == -1)
//             printf("***Element %d not found***\n", x);
//         else
//             printf("***Found %d at location %d***\n", x, loc);
//     }
// }


// void insert(int data[], int flag[], int chain[], int x){
//     int i = 0, j, start;
//     start = h(x);
//     while (flag[start] && i < SIZE){
//         if (data[start] % SIZE == x % SIZE)
//             break;
//         i++;
//         start = (start + 1) % SIZE;
//     }
//     if (i == SIZE){
//         printf("\n**hash table is full***");
//         return;
//     }
//     while (chain[start] != -1)
//         start = chain[start];
//     j = start;
//     while (flag[j] && i < SIZE){
//         j = (j + 1) % SIZE;
//         i = i + 1;
//     }
//     if (i == SIZE)
//     {
//         printf("\n**hash table is full***");
//         return;
//     }
//     data[j] = x;
//     flag[j] = TRUE;
//     if (j != start)
//         chain[start] = j; 
// }

// int search(int data[], int flag[], int chain[], int x){
//     int i = 0, j;
//     j = h(x);
//     while (i < SIZE && flag[j] && data[j] % SIZE != x % SIZE){
//         i++;
//         j = (j + 1) % SIZE;
//     }
//     if (!flag[j] || i == SIZE)
//         return (-1);
//     while (j != -1)
//     {
//         if (data[j] == x)
//             return (j);
//         j = chain[j];
//     }
//     return (-1);
// }

// void print(int data[], int flag[], int chain[]){
//     int i;
//     for (i = 0; i < SIZE; i++)
//         if (flag[i])
//             printf("\n(%d) %d     %d", i, data[i], chain[i]);
//         else
//             printf("\n(%d) ---    %d", i, chain[i]);
// }
