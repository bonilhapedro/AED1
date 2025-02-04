#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[111];
    char color[20];
    char size;
} TShirt;

int cmp(const void *a, const void *b) {
    TShirt *t1 = (TShirt *)a;
    TShirt *t2 = (TShirt *)b;
    
    int cmpColor = strcmp(t1->color, t2->color);
    if(cmpColor != 0)
        return cmpColor;
    
    if(t1->size != t2->size) {
        if(t1->size > t2->size)
            return -1;
        else
            return 1;
    }
    
    return strcmp(t1->name, t2->name);
}

int main(void) {
    int n;
    int firstCase = 1;
    
    while(scanf("%d", &n) == 1 && n != 0) {
        getchar();
        
        TShirt *list = (TShirt *) malloc(n * sizeof(TShirt));
        if(list == NULL) {
            fprintf(stderr, "Erro de alocação.\n");
            return 1;
        }
        
        for (int i = 0; i < n; i++) {
            fgets(list[i].name, 110, stdin);
            size_t len = strlen(list[i].name);
            if(len > 0 && list[i].name[len-1] == '\n')
                list[i].name[len-1] = '\0';
            
            char line[50];
            fgets(line, 50, stdin);
            len = strlen(line);
            if(len > 0 && line[len-1] == '\n')
                line[len-1] = '\0';
            
            sscanf(line, "%s %c", list[i].color, &list[i].size);
        }
        
        qsort(list, n, sizeof(TShirt), cmp);
        
        if(!firstCase)
            printf("\n");
        firstCase = 0;
        
        for (int i = 0; i < n; i++) {
            printf("%s %c %s\n", list[i].color, list[i].size, list[i].name);
        }
        
        free(list);
    }
    return 0;
}
