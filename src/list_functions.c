#include "fillit.h"

void add_to_list(tetrimino_node **list_head, tetrimino_node *new_node)
{
    tetrimino_node *iter = *list_head;

    if (*list_head == NULL)
    {
        *list_head = new_node;
        return;
    }

    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    iter->next = new_node;
}

tetrimino_node *get_new_node(char *figure)
{
    tetrimino_node *node = (tetrimino_node*)malloc(sizeof(tetrimino_node));
    if (node == NULL)
    {
        return NULL;
    }

    node->figure = figure;
    node->next = NULL;

    return (node);
}