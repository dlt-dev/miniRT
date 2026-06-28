# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cybourge <cybourge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 12:34:16 by cybourge          #+#    #+#              #
#    Updated: 2026/06/28 12:21:35 by cybourge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ls -1 src | sed ':a;N;$!ba;s/\n/\\\n/g'
#SRCS = $(wildcard $(SRCS_DIR)/*.c)

CC = cc
C_FLAGS = -Wall -Wextra -Werror -MMD -o3 

RED = \033[31;1;3m
GREEN = \033[32;1;3m
YEL = \033[33;1;3m
CYAN = \033[36;1;3m
VIOLET = \033[1;35m
BLUE = \033[1;34m
RESET = \033[m

COMP_LIBS = -I$(MLXDIR) -I/usr/include
LINK_LIBS = -L$(MLXDIR) -lmlx_Linux -lXext -lX11 -lm -lz

MAKE += --silent --no-print-directory

MLXDIR  = minilibx-linux

LIB_NAME = libmlx_Linux.a
LIB_BIN = $(MLXDIR)/libmlx_Linux.a
MK_MLX = $(MAKE) --silent -C$(MLXDIR) 2>/dev/null

OBJS_DIR = obj
SRCS_DIR = src
DEPS_DIR = $(OBJS_DIR)
INCS_DIR = inc

SRC = cam_gen_ray.c\
cam_ini.c\
cam_prt.c\
cld_cord.c\
cld_crt.c\
cld_hit2.c\
cld_hit.c\
cld_nrml.c\
close_display.c\
clr_add.c\
clr_bld.c\
clr_crt.c\
clr_mul.c\
clr_pack.c\
clr_sub.c\
clr_unpack.c\
con_cord.c\
con_crt.c\
con_hit2.c\
con_hit.c\
con_nrml.c\
deql.c\
display_progressbar.c\
display_progress.c\
free_mlx_data.c\
ft_atof.c\
ft_atoi.c\
ft_bzero.c\
ft_err_prt.c\
ftex_clr.c\
ftex_dlt.c\
ftex_load.c\
ft_memcpy.c\
ft_memset.c\
ft_putchar.c\
ft_putnbr.c\
ft_split.c\
ft_split_utils.c\
ft_strchr.c\
ft_strcmp.c\
ft_strdup.c\
ft_strjoin.c\
ft_strlen.c\
ft_substr.c\
gnl.c\
handle_keypress.c\
handle_x_buton.c\
img_pix_put.c\
init_mlx_data.c\
is_shadowed.c\
is_validclr.c\
is_validf.c\
is_validui.c\
itv_clp.c\
itv_cnt.c\
itv_crt.c\
itv_srd.c\
itx_cal.c\
itx_prt.c\
itxv_add.c\
itxv_clr.c\
itxv_crt.c\
itxv_dlt.c\
itxv_hit.c\
itxv_prt.c\
itxv_sort.c\
lgt_set.c\
lgtv_add.c\
lgtv_clr.c\
lgtv_crt.c\
lgtv_dlt.c\
lgtv_prt.c\
m44_add.c\
m44_cpy.c\
m44_ele.c\
m44_eql.c\
m44_idm.c\
m44_inv.c\
m44_inv_rot.c\
m44_inv_scl.c\
m44_inv_she.c\
m44_inv_trl.c\
m44_mul.c\
m44_prd.c\
m44_prt_bop.c\
m44_prt.c\
m44_prt_uop.c\
m44_prt_vprd.c\
m44_rotx.c\
m44_roty.c\
m44_rotz.c\
m44_scl.c\
m44_she.c\
m44_sub.c\
m44_trl.c\
m44_trp.c\
m44_vprd.c\
m44_vrv.c\
m44_vtrf.c\
m44_zro.c\
minirt.c\
mtl_ini.c\
mtl_prt.c\
mtl_trf.c\
obj_dlt.c\
obj_gclr.c\
objl_add.c\
objl_dlt.c\
objl_free.c\
obj_lgt.c\
objl_isin.c\
objl_last.c\
obj_prt.c\
obj_trf.c\
objv_add.c\
objv_crt.c\
objv_dlt.c\
objv_prt.c\
oty_prt.c\
pat_chkr1.c\
pat_chkr2.c\
pat_lgrad1.c\
pat_ring1.c\
pat_strp1.c\
pln_cord.c\
pln_crt.c\
pln_hit.c\
pln_nrml.c\
prs_ambient.c\
prs_camera.c\
prs_clr.c\
prs_cmplt.c\
prs_cone.c\
prs_cylinder.c\
prs_light.c\
prs_lines.c\
prs_mat.c\
prs_plane.c\
prs_prt.c\
prs_rtfile.c\
prs_sphere.c\
prs_v3.c\
pt_crt.c\
ray_pos.c\
ray_prt.c\
ray_trf.c\
scn_dflt_cam.c\
scn_dflt_lgts.c\
scn_dflt_objs.c\
scn_dflt_objs_cylinders.c\
scn_dflt_objs_spheres.c\
scn_dflt_obs_planes.c\
scn_dlt.c\
scn_render.c\
scn_setup.c\
sph_cord.c\
sph_crt.c\
sph_hit.c\
sph_nrml.c\
tab_dlt.c\
tab_len.c\
texv_add_ftex.c\
texv_add_pat.c\
texv_crt.c\
texv_dlt.c\
tpl_sort.c\
trf_ini.c\
trf_rot.c\
trf_scl.c\
trf_she.c\
trf_trf.c\
trf_trl.c\
v4_add.c\
v4_crt.c\
v4_div.c\
v4_dot.c\
v4_eql.c\
v4_inv.c\
v4_len.c\
v4_lprt.c\
v4_lsq.c\
v4_mul.c\
v4_prt_bop.c\
v4_prt.c\
v4_prt_uop.c\
v4_rfl.c\
v4_sub.c\
v4_uni.c\
v4_xpr.c\
wld_add_lgt.c\
wld_add_obj.c\
wld_clr_at.c\
wld_crt_dflt.c\
wld_dlt.c\
wld_itx.c\
wld_prt.c\
wld_shd.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

NAME = miniRT

all: $(NAME)

bonus: all

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(C_FLAGS) -I$(INCS_DIR) $(COMP_LIBS) -c $< -o $@


$(MLXDIR):
	@printf "$(CYAN)Cloning MiniLibX...$(RESET)\n"
	@if [ ! -d "$(MLXDIR)" ]; then \
		git clone https://github.com/42paris/minilibx-linux.git $(MLXDIR); fi
	

$(NAME): $(MLXDIR) $(OBJS) $(LIB_BIN)
	@printf "$(BLUE)Linking files at light speed...$(RESET)\n"
	@$(CC) $(C_FLAGS) $(OBJS) $(LINK_LIBS) -o $@
	@printf "$(VIOLET)The journey is over!$(RESET)\n"

$(LIB_BIN): $(MLXDIR)
	@printf "$(CYAN)Building MiniLibX...$(RESET)\n"
	@$(MAKE) -C $(MLXDIR)
	@printf "$(GREEN)MiniLibX ready!$(RESET)\n"

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  --track-fds=yes ./miniRT

clean:
	rm -rf $(OBJS_DIR)
	@if [ -d "$(MLXDIR)" ]; then $(MAKE) clean -C $(MLXDIR); fi

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLXDIR)
	
re: fclean
	@$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
