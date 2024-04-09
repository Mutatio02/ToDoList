#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// TO DO LIST PROGRAM by Mutatio02 (23.11.08 ~ 23.11.22)
void startScreen(); // Start Screen function
void menuScreen(); // menu + select Screen function
void quitScreen(); // 4. quit Screen
char todoScreen(); // 1. make list Screen
void seetodoScreen(); //3. to see make list Screen

typedef struct TODO {
    char List[101];
    struct TODO* Next;
}TODO; 
TODO* todo;
int main(void) 
{
    startScreen(); // startScreen화면 출력
    system("cls"); 
    
    while (1)
    {
        menuScreen(); // menuScreen화면 출력
        putchar('\n'); // 개행
        int Number = 0; // 사용자 번호선택
        printf("\t\t\t\t\t  Select number: ");
        scanf_s("%d%*c", &Number);

        if (Number == 1)
            todoScreen(); // 1번함수
        else if (Number == 2)
            printf("2번함수 실행"); // 2번함수
        else if (Number == 3)
            seetodoScreen(todo); // 3번함수 // seetodoScreen(&todo);
        else if (Number == 4)
        {
            quitScreen();
            break;
        }// 4번함수
        else
        {
            putchar('\n'); // 개행
            putchar('\n');
            printf("\t\t\t\t\t  Sorry you entered an incorrect number :(");
            
            return 0;
        }
        
    }
    return 0;
}

void startScreen(void)
{
    system("color 3F");
    printf("\n\n\n\n\n\n");

    printf("\t\t\t\t  Welcome to the To DO List Program  :):):):)\n");
    putchar('\n');
    putchar('\n');

    printf("\t\t\t\t  --------------------------------------------\n");
    printf("\t\t\t\t  --------------------------------------------\n");
    putchar('\n');
    putchar('\n');

    printf("\t\t\t\t  If you Press any key, It will start :):):):)");
    putchar('\n');
    putchar('\n');

    getchar();
    system("cls");
}
void menuScreen(void)
{
    printf("\n\n\n\n\n\n");

    printf("\t\t\t\t\t  1. TO Make your To do List");
    putchar('\n');
    putchar('\n');

    printf("\t\t\t\t\t  2. To Remove your To do List");
    putchar('\n');
    putchar('\n');

    printf("\t\t\t\t\t  3. To see your To do List");
    putchar('\n');
    putchar('\n');

    printf("\t\t\t\t\t  4. Quit");
    putchar('\n');
    putchar('\n');
}
void quitScreen()
{
    system("cls");
    
    printf("\n\n\n\n\n\n");
    
    printf("\t\t\t\t Thank you for accessing my to do list program :)");
    getchar(); //개행문자
    system("cls");
    
}
char todoScreen()
{
    char answer = 0;
    system("cls");
    todo = (TODO*)malloc(sizeof(TODO));
    if (todo != NULL)
    {
        printf("Please write your list!\n");
        fflush(stdin);
        gets_s(todo->List, sizeof(todo->List));
    }
    else
        printf("Sorry about the Error");
    putchar('\n');
    while (1)
    {
        printf("DO you want to make another List? (y or n)\n");
        scanf_s("%c%*c",&answer); 
        putchar('\n'); // 개행
        
        if (answer == 'y')
        {
            printf("Please write your list!\n");
            fflush(stdin); 
            gets_s(todo->List, sizeof(todo->List));
            putchar('\n');
        }
        else if (answer == 'n')
        {
            printf("Thank you for making the List!\n");
            getchar();
            break;
        }
        else
        {
            printf("sorry about the error\n");
            system("cls");
            break;    
        }
    }
    fflush(stdin);
    system("cls");
    
    return answer;
}
void seetodoScreen(TODO* seeparam)
{

    if (seeparam == NULL)
    {
        putchar('\n'); // 개행
        putchar('\n'); // 개행
        printf("\t\t\t\t\t  There is no List\n");
        // 리스트 작성 없이 바로 3번 실행의 경우
    }
    else
    {
        system("cls");
        printf("%s\n", seeparam->List);
        getchar();
    }
}