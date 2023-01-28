/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:37:53 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/28 01:33:41 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    map *carte;
    
    carte = (map*)malloc(sizeof(map));
    file_error(argc, argv);
    get_map_infos(carte, argv[1]);
    return (0);
}