#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctime>

// greatswercporto

using namespace std;

vector<string> permutes(100000000);
int index_permute = 0;

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
    int i;
    if (l == r) {
        string str(a);
        permutes[index_permute++] = str;
        //printf("%s\n", a);
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i)); //backtrack
        }
    }
}

void findDistinct (char ascii[], char input[]) {
    for (int d = 0; input[d] != '\0'; d++) {
        ascii[input[d]]++;
    }
}

int main () {
    clock_t start;
    double duration;
    
    start = clock();

    char arr[11];
    char input[11];
    char ascii[300] = {0};
    int numWords, index = 0;
    scanf("%d", &numWords);
    for (int i = 0; i < numWords-1; i++) {
        scanf("%s", input);
        findDistinct(ascii, input);
    }
    
    scanf("%s", input);
    findDistinct(ascii, input);
    
    
    for (int i = 65; i <= 90; i++) {
        if (ascii[i]) arr[index++] = i;
    }
    
    arr[index] = '\0';
    permute(arr, 0, strlen(arr)-1);
    
    for (int i = 0; i < index_permute; i++) {
        // Assign the values to input;
        for (int x = 0; x < 3; x++) {
            char mystr[11];
            int mystr_index = 0;
            for (int d = 0; input[d] != '\0'; d++) {
                for (int c = 0; c < permutes[0].size(); c++) {
                    if (input[d] == permutes[i][c]) {
                        mystr[mystr_index++] = c + '0';
                        break;
                    }
                }
            }
            mystr[mystr_index] = '\0';
            atoi(mystr);
        }
        
    }
    cout << index_permute << endl;
    


    cout << "Answer: " << input << endl;
    
    
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    cout << "Duration: " << duration << endl;

}
