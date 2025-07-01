/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:55:57 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/01 22:00:06 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_right_line(t_data *data, t_map *map, int x, int y)
{
    t_point a;
    t_point b;
    t_iso_ctx ctx_a;
    t_iso_ctx ctx_b;
    t_line_ctx line_ctx;

    ctx_a.x = x;
    ctx_a.y = y;
    ctx_a.z = map->map[y][x];
    a = project_iso(ctx_a);

    if (x < map->map_width - 1)
    {
        ctx_b.x = x + 1;
        ctx_b.y = y;
        ctx_b.z = map->map[y][x + 1];
        b = project_iso(ctx_b);

        line_ctx.a = a;
        line_ctx.b = b;
        line_ctx.img = data;
        line_ctx.color_a = map->color_map[y][x];
        line_ctx.color_b = map->color_map[y][x + 1];
        draw_line_colored(line_ctx);
    }
}

// Helper to draw line to down neighbor if exists
void draw_down_line(t_data *data, t_map *map, int x, int y)
{
    t_point a;
    t_point b;
    t_iso_ctx ctx_a;
    t_iso_ctx ctx_b;
    t_line_ctx line_ctx;

    ctx_a.x = x;
    ctx_a.y = y;
    ctx_a.z = map->map[y][x];
    a = project_iso(ctx_a);

    if (y < map->map_height - 1)
    {
        ctx_b.x = x;
        ctx_b.y = y + 1;
        ctx_b.z = map->map[y + 1][x];
        b = project_iso(ctx_b);

        line_ctx.a = a;
        line_ctx.b = b;
        line_ctx.img = data;
        line_ctx.color_a = map->color_map[y][x];
        line_ctx.color_b = map->color_map[y + 1][x];
        draw_line_colored(line_ctx);
    }
}

void draw_line_neighbors(t_data *data, t_map *map, int x, int y)
{
    draw_right_line(data, map, x, y);
    draw_down_line(data, map, x, y);
}

void render_map(t_data *data, t_map *map)
{
    int x;
    int y;

    mlx_clear_window(data->mlx, data->win);

    y = 0;
    while (y < map->map_height)
    {
        x = 0;
        while (x < map->map_width)
        {
            draw_line_neighbors(data, map, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

// Open file and parse map or return NULL on failure
t_map *open_and_parse_map(const char *filename)
{
    int fd;
    t_map *map_data;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);

    map_data = parse_map(fd);
    close(fd);
    return (map_data);
}
