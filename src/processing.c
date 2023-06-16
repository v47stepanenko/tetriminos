/* #include "fillit.h"

char *cut_figure(tetrimino_node *tetri, int counter);
int countColumns(char *hashFigure, int horizontalLeft);
char *copyHash(char *hashFigure, char *resultFigure, int horizontalLeft, int verticalLeft);

char *convert_tetri(char *figure, int counter)
{
    size_t i = 0;
    while (figure[i] != '\0')
    {
        if (figure[i] == '#')
        {
            figure[i] = 'A' + counter;
            i++;
        } 
        else 
        i++;
    }
    return figure;
}


tetrimino_node *processing(tetrimino_node *figures)
{
    tetrimino_node *cutOut = NULL;
    int newlistFigureCounter = 0;
    char *tetri;

    while (figures != NULL)
    {    
        tetri = cut_figure(figures, newlistFigureCounter);
        tetrimino_node *figureNode = lstnew(tetri, newlistFigureCounter);
        cutOut = add_to_list(cutOut, figureNode);
        newlistFigureCounter++;
        figures = figures->next; 
    }
    
    free(figures);
    return cutOut;
}

char *cut_figure(tetrimino_node *tetri, int counter)
{
    tetrimino_node *temp = tetri;
    int p = 0;
    int multh = 0;
    int i;
    int horizontalLeft = 0;
    int verticalLeft = 0;
    int square;
    char *single_figure;
    char *tempFigure = NULL;
    char *hashFigure = NULL;
    char *resultFigure = NULL;
   
    single_figure = ft_strdup(temp->figure);
    while(p <= 15) //0
    {
        multh = 0;
        while (multh < 4 && p <= 15) //0
        {
            i = p + multh;
            if (single_figure[i] == '#')
            {
                horizontalLeft++;
                if (hashFigure == NULL)
                    hashFigure = ft_strndup(&single_figure[i - multh], 5);
                else
                    hashFigure = ft_strncat_m(hashFigure, &single_figure[i - multh], 5); 

                break;         
            }
            else
            {
                multh++;
                i = p + multh;
            }           
        } 
        
        if (p >= 16)
            break;
    
        tempFigure = ft_strsub(single_figure, p, ft_strlen(single_figure) - p);
        i = 0;
        p += 5;
    }
            
    p = 0;
    i = 0;
    ft_strdel(&tempFigure);   

    verticalLeft = countColumns(hashFigure, horizontalLeft);
    square = (horizontalLeft * (verticalLeft + 1));
    resultFigure = ft_strnew(square);
    resultFigure = copyHash(hashFigure, resultFigure, horizontalLeft, verticalLeft);
    resultFigure = convert_tetri(resultFigure, counter);
    return resultFigure;
} 

int countColumns(char *hashFigure, int horizontalLeft)
{        
    int i = 0;
    int p = 0;
    int multv = 0;
    int columnCounter = 0;
    int multiplier = 5 * (horizontalLeft - 1);

    while(p <= 3)//0
    {
        while (multv <= multiplier && p <= 3) 
        {
            i = p + multv;
            if (hashFigure[i] == '#')
            {
                columnCounter++;
                break;           
            }
            else
              multv += 5;                       
        } 
        p++;
        multv = 0;
    }
    return (columnCounter);
} 

char *copyHash(char *hashFigure, char *resultFigure, int horizontalLeft, int verticalLeft)
{        
    int i = 0;
    int j = 0;
    int p = 0;
    int s = 0;
    int multv = 0;
    int multj = 0;
    int found = 0;
   // int charCounter = 0;
    int multiplier = 5 * (horizontalLeft - 1);
    int square = (horizontalLeft * (verticalLeft + 1));

    while(p <= 3) //0
    {
        while (multv <= multiplier && p <= 3) 
        {
            i = p + multv;
            j = s + multj;
            //  printf("%c\n", single_figure[i]);
            if (hashFigure[i] == '#')
            {
                
                ft_strncpy(&resultFigure[j], &hashFigure[i], 1);
                multv += 5;
                multj += (verticalLeft+1);
                found++;

            }

            else
            {
            //    printf("no # found in %d column\n", p);
                multv += 5;
                multj += (verticalLeft+1);
            }           
        } 
        if (found > 0)
            {
                found = 0;
                s++;
                p++;
                multv = 0;
                multj = 0;
            }
        else 
        {
            //printf("last print in %d column\n", verticalLeft);
            p++;
            multv = 0;
            multj = 0;
        }
    }

    i = verticalLeft;
//printf("square is %d\n", square);
    while (i <= square)
    {
      resultFigure[i] = '\n';
      i += (verticalLeft + 1);
    }

    i = 0;
    while (i < square)
    {
        if (resultFigure[i] == '\0')
           resultFigure[i] = '.';
        i++;
    }


    return (resultFigure);
}


 */