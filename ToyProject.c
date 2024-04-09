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
    startScreen(); // startScreenȭ�� ���
    system("cls"); 
    
    while (1)
    {
        menuScreen(); // menuScreenȭ�� ���
        putchar('\n'); // ����
        int Number = 0; // ����� ��ȣ����
        printf("\t\t\t\t\t  Select number: ");
        scanf_s("%d%*c", &Number);

        if (Number == 1)
            todoScreen(); // 1���Լ�
        else if (Number == 2)
            printf("2���Լ� ����"); // 2���Լ�
        else if (Number == 3)
            seetodoScreen(todo); // 3���Լ� // seetodoScreen(&todo);
        else if (Number == 4)
        {
            quitScreen();
            break;
        }// 4���Լ�
        else
        {
            putchar('\n'); // ����
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
    getchar(); //���๮��
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
        putchar('\n'); // ����
        
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
        putchar('\n'); // ����
        putchar('\n'); // ����
        printf("\t\t\t\t\t  There is no List\n");
        // ����Ʈ �ۼ� ���� �ٷ� 3�� ������ ���
    }
    else
    {
        system("cls");
        printf("%s\n", seeparam->List);
        getchar();
    }
}