//
//  main.c
//  FAT-2
//
//  Created by Aaron R on 09/12/21.
//  You are given some letters and asked to find all the possible words using an almost complete binary tree. For example, given eight letters {a, b, c, d, e, f, g,h}, construct an almost complete binary tree as given below. A possible word is one which starts from the root node and ends at the leaf node. In the given example the possible words are {abdh, abe, acf, acg}. At least one letter is necessary to form a word. If the entry is less than one then print ‘Invalid’. Write a code to get all the possible words given a set of letters using an almost complete binary tree. The words should be printed from left to right of the binary tree.

//Input Format:

//In the first line, enter the number of letters n
//In the second line, enter all the n letters

//Output Format: All possible words, each in a new line

//Sample Input 1:
//8
//a b c d e f g h

//Sample Output 1:
//abdh
//abe

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(char arr[], struct Node* root, int i, int n) {
    if (i<n) {
        struct Node* temp = malloc(sizeof(struct Node));
        temp->data = arr[i];
        root = temp;

        root->left = insert(arr, root->left, 2*i + 1, n);
        root->right = insert(arr, root->right, 2*i + 2, n);
    }
    return root;
}

void pre_order(struct Node* top) {
    if (top == NULL)
        return;
    else {
        printf("%c ", top->data);
        pre_order(top->left);
        pre_order(top->right);
    }
}

void print_words(struct Node* top) {
    static int pos = 0;
    static int size = 0;
    static char word[100] = "";

    if (top == NULL)
        return;
    else if (top->left==NULL && top->right==NULL) {
        word[size++] = top->data;
        printf("%s\n", word);
    }
    else if (pos == 0) {
        word[size++] = top->data;
        pos++;
        print_words(top->left);
        // print_words(top->right); // uncomment this to print right tree as well
    }
    else {
        word[size++] = top->data;
        print_words(top->left);
        print_words(top->right);
    }

    word[size--] = '\0';
}

int main()
{
    struct Node* btree = NULL;
    int n;
    char arr[100];
    scanf("%d\n", &n);
    if (n<1)
        printf("invalid");
    else
        for(int i=0; i<n; i++) {
            scanf("%c", &arr[i]);
        }
    
    btree = insert(arr, btree, 0, n);
    print_words(btree);
    return 0;
}
