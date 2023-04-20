/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.03.04 17:45:23 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	void render_world_tl_reset()
	{
		matrix_world_reset();
		render_set_culling(true);
		global::shader_texture_filter_linear = false;
		global::shader_texture_filter_mipmap = false;
		global::shader_blend_color = c_white;
		global::shader_blend_alpha = IntType(1);
		render_set_uniform_color(/*"uBlendColor"*/ STR(1884), global::shader_blend_color, global::shader_blend_alpha);
		global::shader_uniform_color_ext = IntType(0);
		global::shader_uniform_rgb_add = c_black;
		global::shader_uniform_hsb_add = c_black;
		global::shader_uniform_rgb_sub = c_black;
		global::shader_uniform_hsb_sub = c_black;
		global::shader_uniform_hsb_mul = c_white;
		global::shader_uniform_mix_color = c_black;
		global::shader_uniform_mix_percent = IntType(0);
		render_set_uniform_int(/*"uColorsExt"*/ STR(2040), global::shader_uniform_color_ext);
		render_set_uniform_color(/*"uRGBAdd"*/ STR(2041), global::shader_uniform_rgb_add, IntType(1));
		render_set_uniform_color(/*"uHSBAdd"*/ STR(2043), global::shader_uniform_hsb_add, IntType(1));
		render_set_uniform_color(/*"uRGBSub"*/ STR(2042), global::shader_uniform_rgb_sub, IntType(1));
		render_set_uniform_color(/*"uHSBSub"*/ STR(2044), global::shader_uniform_hsb_sub, IntType(1));
		render_set_uniform_color(/*"uHSBMul"*/ STR(2045), global::shader_uniform_hsb_mul, IntType(1));
		render_set_uniform_color(/*"uMixColor"*/ STR(2046), global::shader_uniform_mix_color, global::shader_uniform_mix_percent);
		render_set_uniform_int(/*"uMaterialFormat"*/ STR(2465), e_material_FORMAT_NONE);
		global::shader_uniform_emissive = IntType(0);
		render_set_uniform(/*"uEmissive"*/ STR(2470), global::shader_uniform_emissive);
		global::shader_uniform_metallic = IntType(0);
		render_set_uniform(/*"uMetallic"*/ STR(2468), IntType(0));
		global::shader_uniform_roughness = IntType(0);
		render_set_uniform(/*"uRoughness"*/ STR(2469), global::shader_uniform_roughness);
		global::shader_uniform_wind = false;
		global::shader_uniform_wind_terrain = false;
		render_set_uniform(/*"uWindEnable"*/ STR(1886), global::shader_uniform_wind);
		render_set_uniform(/*"uWindTerrain"*/ STR(1887), global::shader_uniform_wind_terrain);
		global::shader_uniform_fog = true;
		render_set_uniform_int(/*"uFogShow"*/ STR(1893), global::shader_uniform_fog);
		global::shader_uniform_sss = IntType(0);
		global::shader_uniform_sss_red = IntType(1);
		global::shader_uniform_sss_green = IntType(1);
		global::shader_uniform_sss_blue = IntType(1);
		global::shader_uniform_sss_color = c_white;
		render_set_uniform(/*"uSSS"*/ STR(2478), global::shader_uniform_sss);
		render_set_uniform_vec3(/*"uSSSRadius"*/ STR(2479), global::shader_uniform_sss_red, global::shader_uniform_sss_green, global::shader_uniform_sss_blue);
		render_set_uniform_color(/*"uSSSColor"*/ STR(2480), global::shader_uniform_sss_color, 1.0);
		global::shader_uniform_wind_strength = global::_app->background_wind_strength * (IntType)global::_app->setting_wind_enable;
		global::shader_uniform_glow = false;
		global::shader_uniform_glow_texture = false;
		global::shader_uniform_glow_color = c_white;
		global::render_blend_prev = null_;
		global::render_alpha_prev = null_;
	}
	
	void res_copy(ScopeAny self, IntType to)
	{
		idVar(to, type) = sVar(type);
		idVar(to, filename) = sVar(filename);
		idVar(to, display_name) = sVar(display_name);
		idVar(to, player_skin) = sVar(player_skin);
		idVar(to, item_sheet_size) = array_copy_1d(sVar(item_sheet_size));
		idVar(to, scenery_tl_add) = sVar(scenery_tl_add);
		idVar(to, scenery_download_skins) = sVar(scenery_download_skins);
		idVar(to, world_regions_dir) = sVar(world_regions_dir);
		idVar(to, world_box_start) = sVar(world_box_start);
		idVar(to, world_box_end) = sVar(world_box_end);
		idVar(to, world_filter_mode) = sVar(world_filter_mode);
		idArr(to, world_filter_array) = sArr(world_filter_array);
		idVar(to, scenery_integrity) = sVar(scenery_integrity);
		idVar(to, scenery_integrity_invert) = sVar(scenery_integrity_invert);
		idVar(to, scenery_palette) = sVar(scenery_palette);
		idVar(to, scenery_randomize) = sVar(scenery_randomize);
		idVar(to, material_format) = sVar(material_format);
	}
	
	void res_event_create(Scope<obj_resource> self)
	{
		self->save_id = /*""*/ STR(0);
		self->save_id = save_id_create();
		self->loaded = false;
		self->creator = global::res_creator;
		self->replaced = false;
		self->ready = true;
		self->type = null_;
		self->filename = /*""*/ STR(0);
		self->display_name = /*""*/ STR(0);
		self->count = IntType(0);
		self->copied = false;
		self->pattern_type = /*""*/ STR(0);
		self->model_file = null_;
		self->model_format = null_;
		self->model_texture = null_;
		self->model_texture_map = null_;
		self->model_texture_material_map = null_;
		self->model_tex_normal_map = null_;
		self->model_block_map = null_;
		self->model_texture_name_map = null_;
		self->model_texture_material_name_map = null_;
		self->model_tex_normal_name_map = null_;
		self->model_shape_texture_name_map = null_;
		self->model_shape_texture_material_name_map = null_;
		self->model_shape_tex_normal_name_map = null_;
		self->model_color_name_map = null_;
		self->model_color_map = null_;
		self->model_shape_hide_list = null_;
		self->model_shape_vbuffer_map = null_;
		self->model_shape_alpha_map = null_;
		self->player_skin = false;
		self->pack_format = e_minecraft_pack_LATEST;
		self->block_sheet_texture = null_;
		self->block_sheet_texture_material = null_;
		self->block_sheet_tex_normal = null_;
		self->block_sheet_ani_texture = null_;
		self->block_sheet_ani_texture_material = null_;
		self->block_sheet_ani_tex_normal = null_;
		self->block_sheet_depth_list = null_;
		self->block_sheet_ani_depth_list = null_;
		self->block_preview_texture = null_;
		self->colormap_grass_texture = null_;
		self->colormap_foliage_texture = null_;
		self->color_grass = null_;
		self->color_leaves_oak = null_;
		self->color_leaves_spruce = null_;
		self->color_leaves_birch = null_;
		self->color_leaves_jungle = null_;
		self->color_leaves_acacia = null_;
		self->color_leaves_dark_oak = null_;
		self->color_leaves_mangrove = null_;
		self->color_foliage = null_;
		self->color_water = null_;
		self->sun_texture = null_;
		self->moonphases_texture = null_;
		self->moon_texture[IntType(0)] = null_;
		self->clouds_texture = null_;
		self->item_sheet_texture = null_;
		self->item_sheet_texture_material = null_;
		self->item_sheet_tex_normal = null_;
		self->item_sheet_size = vec2(item_sheet_width, item_sheet_height);
		self->particles_texture[IntType(0)] = null_;
		self->particles_texture[IntType(1)] = null_;
		self->particle_texture_atlas_map = null_;
		self->particle_texture_uvs_map = null_;
		self->particle_texture_pixeluvs_map = null_;
		self->block_vbuffer = null_;
		self->scenery_tl_add = null_;
		self->scenery_tl_list = null_;
		self->scenery_size = vec3(IntType(0));
		self->world_regions_dir = /*""*/ STR(0);
		self->world_box_start = null_;
		self->world_box_end = null_;
		self->world_filter_mode = IntType(0);
		self->world_filter_array = ArrType();
		self->scenery_download_skins = true;
		self->scenery_structure = false;
		self->scenery_integrity = IntType(1);
		self->scenery_integrity_invert = false;
		self->scenery_palette = IntType(0);
		self->scenery_palette_size = IntType(0);
		self->scenery_randomize = true;
		self->texture = null_;
		self->font = null_;
		self->font_preview = null_;
		self->font_no_aa = null_;
		self->font_minecraft = false;
		self->sound_buffer = null_;
		self->sound_index = null_;
		self->sound_samples = IntType(0);
		self->sound_max_sample = ArrType();
		self->sound_min_sample = ArrType();
		self->load_stage = /*""*/ STR(0);
		self->load_audio_sample = IntType(0);
		self->material_format = e_material_FORMAT_LABPBR;
	}
	
	void res_event_destroy(ScopeAny self)
	{
		if (sInt(model_texture) != null_)
			texture_free(sInt(model_texture));
		if (sInt(model_texture_map) != null_)
		{
			VarType key = ds_map_find_first(sInt(model_texture_map));
			while (!is_undefined(key))
			{
				texture_free(DsMap(sInt(model_texture_map)).Value(key));
				key = ds_map_find_next(sInt(model_texture_map), key);
			}
			
			ds_map_destroy(sInt(model_texture_map));
		}
		if (sInt(model_texture_material_map) != null_)
		{
			VarType key = ds_map_find_first(sInt(model_texture_material_map));
			while (!is_undefined(key))
			{
				texture_free(DsMap(sInt(model_texture_material_map)).Value(key));
				key = ds_map_find_next(sInt(model_texture_material_map), key);
			}
			
			ds_map_destroy(sInt(model_texture_material_map));
		}
		if (sInt(model_tex_normal_map) != null_)
		{
			VarType key = ds_map_find_first(sInt(model_tex_normal_map));
			while (!is_undefined(key))
			{
				texture_free(DsMap(sInt(model_tex_normal_map)).Value(key));
				key = ds_map_find_next(sInt(model_tex_normal_map), key);
			}
			
			ds_map_destroy(sInt(model_tex_normal_map));
		}
		if (sInt(model_shape_vbuffer_map) != null_)
		{
			VarType key = ds_map_find_first(sInt(model_shape_vbuffer_map));
			while (!is_undefined(key))
			{
				if (instance_exists(key) && idVar(key, vbuffer_default) != DsMap(sInt(model_shape_vbuffer_map)).Value(key))
					vbuffer_destroy(DsMap(sInt(model_shape_vbuffer_map)).Value(key));
				key = ds_map_find_next(sInt(model_shape_vbuffer_map), key);
			}
			
			ds_map_destroy(sInt(model_shape_vbuffer_map));
		}
		if (sInt(model_shape_alpha_map) != null_)
			ds_map_destroy(sInt(model_shape_alpha_map));
		if (sVar(block_sheet_texture) != null_)
			texture_free(sVar(block_sheet_texture));
		if (sVar(block_sheet_texture_material) != null_)
			texture_free(sVar(block_sheet_texture_material));
		if (sVar(block_sheet_tex_normal) != null_)
			texture_free(sVar(block_sheet_tex_normal));
		if (sVar(block_sheet_ani_texture) != null_)
			for (IntType f = IntType(0); f < block_sheet_ani_frames; f++)
				texture_free(sVar(block_sheet_ani_texture).Value(f));
		if (sVar(block_sheet_ani_texture_material) != null_)
			for (IntType f = IntType(0); f < block_sheet_ani_frames; f++)
				texture_free(sVar(block_sheet_ani_texture_material).Value(f));
		if (sVar(block_sheet_ani_tex_normal) != null_)
			for (IntType f = IntType(0); f < block_sheet_ani_frames; f++)
				texture_free(sVar(block_sheet_ani_tex_normal).Value(f));
		if (sInt(block_sheet_depth_list) != null_)
			ds_list_destroy(sInt(block_sheet_depth_list));
		if (sInt(block_sheet_ani_depth_list) != null_)
			ds_list_destroy(sInt(block_sheet_ani_depth_list));
		if (sInt(block_preview_texture) != null_)
			texture_free(sInt(block_preview_texture));
		block_vbuffer_destroy(self);
		if (sInt(item_sheet_texture) != null_)
			texture_free(sInt(item_sheet_texture));
		if (sInt(item_sheet_texture_material) != null_)
			texture_free(sInt(item_sheet_texture_material));
		if (sInt(item_sheet_tex_normal) != null_)
			texture_free(sInt(item_sheet_tex_normal));
		if (sInt(colormap_grass_texture) != null_)
			texture_free(sInt(colormap_grass_texture));
		if (sInt(colormap_foliage_texture) != null_)
			texture_free(sInt(colormap_foliage_texture));
		if (sArr(particles_texture).Value(IntType(0)) != null_)
			texture_free(sArr(particles_texture).Value(IntType(0)));
		if (sArr(particles_texture).Value(IntType(1)) != null_)
			texture_free(sArr(particles_texture).Value(IntType(1)));
		if (sVar(sun_texture) != null_)
			texture_free(sVar(sun_texture));
		if (sInt(moonphases_texture) != null_)
		{
			texture_free(sInt(moonphases_texture));
			for (IntType t = IntType(0); t < IntType(8); t++)
				texture_free(sArr(moon_texture).Value(t));
		}
		if (sVar(clouds_texture) != null_)
			texture_free(sVar(clouds_texture));
		if (sVar(texture) != null_)
			texture_free(sVar(texture));
		if (font_exists(sInt(font)))
			font_delete(sInt(font));
		if (font_exists(sInt(font_preview)))
			font_delete(sInt(font_preview));
		if (font_exists(sInt(font_no_aa)))
			font_delete(sInt(font_no_aa));
		if (sInt(sound_index) != null_)
			audio_free_buffer_sound(sInt(sound_index));
		if (sInt(sound_buffer) != null_)
			buffer_delete(sInt(sound_buffer));
		if (sInt(scenery_tl_list) != null_)
		{
			for (IntType i = IntType(0); i < ds_list_size(sInt(scenery_tl_list)); i++)
				withOne (Object, DsList(sInt(scenery_tl_list)).Value(i), self->id)
					instance_destroy(self);
			
			ds_list_destroy(sInt(scenery_tl_list));
		}
		if (sInt(model_block_map) != null_)
		{
			VarType key = ds_map_find_first(sInt(model_block_map));
			while (!is_undefined(key))
			{
				vbuffer_destroy(DsMap(sInt(model_block_map)).Value(key));
				key = ds_map_find_next(sInt(model_block_map), key);
			}
			
			ds_map_destroy(sInt(model_block_map));
		}
		withAll (obj_template, self->id)
		{
			if (self->model == self.otherId)
				self->model = null_;
			if (self->model_tex == self.otherId)
			{
				self->model_tex = global::mc_res;
				idInt(self->model_tex, count)++;
			}
			if (self->model_tex_material == self.otherId)
			{
				self->model_tex_material = global::mc_res;
				idInt(self->model_tex_material, count)++;
			}
			if (self->model_tex_normal == self.otherId)
			{
				self->model_tex_normal = global::mc_res;
				idInt(self->model_tex_normal, count)++;
			}
			if (self->item_tex == self.otherId)
			{
				self->item_tex = global::mc_res;
				idInt(self->item_tex, count)++;
				render_generate_item(ScopeAny(self));
			}
			if (self->item_tex_material == self.otherId)
			{
				self->item_tex_material = global::mc_res;
				idInt(self->item_tex_material, count)++;
			}
			if (self->item_tex_normal == self.otherId)
			{
				self->item_tex_normal = global::mc_res;
				idInt(self->item_tex_normal, count)++;
			}
			if (self->block_tex == self.otherId)
			{
				self->block_tex = global::mc_res;
				idInt(self->block_tex, count)++;
			}
			if (self->block_tex_material == self.otherId)
			{
				self->block_tex_material = global::mc_res;
				idInt(self->block_tex_material, count)++;
			}
			if (self->block_tex_normal == self.otherId)
			{
				self->block_tex_normal = global::mc_res;
				idInt(self->block_tex_normal, count)++;
			}
			if (self->scenery == self.otherId)
				self->scenery = null_;
			if (self->shape_tex == self.otherId)
				self->shape_tex = null_;
			if (self->shape_tex_material == self.otherId)
				self->shape_tex_material = null_;
			if (self->shape_tex_normal == self.otherId)
				self->shape_tex_normal = null_;
			if (self->text_font == self.otherId)
			{
				self->text_font = global::mc_res;
				idInt(self->text_font, count)++;
			}
		}
		
		withOne (obj_bench_settings, global::_app->bench_settings, self->id)
		{
			if (self->model == self.otherId)
				self->model = null_;
			if (self->model_tex == self.otherId)
				self->model_tex = global::mc_res;
			if (self->model_tex_material == self.otherId)
				self->model_tex_material = global::mc_res;
			if (self->model_tex_normal == self.otherId)
				self->model_tex_normal = global::mc_res;
			if (self->item_tex == self.otherId)
			{
				self->item_tex = global::mc_res;
				render_generate_item(ScopeAny(self));
			}
			if (self->item_tex_material == self.otherId)
			{
				self->item_tex_material = global::mc_res;
				render_generate_item(ScopeAny(self));
			}
			if (self->item_tex_normal == self.otherId)
			{
				self->item_tex_normal = global::mc_res;
				render_generate_item(ScopeAny(self));
			}
			if (self->block_tex == self.otherId)
				self->block_tex = global::mc_res;
			if (self->block_tex_material == self.otherId)
				self->block_tex_material = global::mc_res;
			if (self->block_tex_normal == self.otherId)
				self->block_tex_normal = global::mc_res;
			if (self->shape_tex == self.otherId)
				self->shape_tex = null_;
			if (self->shape_tex_material == self.otherId)
				self->shape_tex_material = null_;
			if (self->shape_tex_normal == self.otherId)
				self->shape_tex_normal = null_;
			if (self->text_font == self.otherId)
				self->text_font = global::mc_res;
			if (self->scenery == self.otherId)
				self->scenery = null_;
		}
		
		withAll (obj_particle_type, self->id)
		{
			if (self->sprite_tex == self.otherId)
			{
				self->sprite_tex = global::mc_res;
				idInt(self->sprite_tex, count)++;
			}
			if (self->sprite_template_tex == self.otherId)
			{
				self->sprite_template_tex = global::mc_res;
				idInt(self->sprite_template_tex, count)++;
			}
		}
		
		withAll (obj_keyframe, self->id)
		{
			if (self->value.Value(e_value_TEXTURE_OBJ) == self.otherId)
				self->value[e_value_TEXTURE_OBJ] = null_;
			if (self->value.Value(e_value_TEXTURE_MATERIAL_OBJ) == self.otherId)
				self->value[e_value_TEXTURE_MATERIAL_OBJ] = null_;
			if (self->value.Value(e_value_TEXTURE_NORMAL_OBJ) == self.otherId)
				self->value[e_value_TEXTURE_NORMAL_OBJ] = null_;
			if (self->value.Value(e_value_SOUND_OBJ) == self.otherId)
				self->value[e_value_SOUND_OBJ] = null_;
			if (self->value.Value(e_value_TEXT_FONT) == self.otherId)
				self->value[e_value_TEXT_FONT] = null_;
		}
		
		withAll (obj_timeline, self->id)
		{
			if (self->value.Value(e_value_TEXTURE_OBJ) == self.otherId)
				self->value[e_value_TEXTURE_OBJ] = null_;
			if (self->value.Value(e_value_TEXTURE_MATERIAL_OBJ) == self.otherId)
				self->value[e_value_TEXTURE_MATERIAL_OBJ] = null_;
			if (self->value.Value(e_value_TEXTURE_NORMAL_OBJ) == self.otherId)
				self->value[e_value_TEXTURE_NORMAL_OBJ] = null_;
			if (self->value_inherit.Value(e_value_TEXTURE_OBJ) == self.otherId)
				self->update_matrix = true;
			if (self->value_inherit.Value(e_value_TEXTURE_MATERIAL_OBJ) == self.otherId)
				self->update_matrix = true;
			if (self->value_inherit.Value(e_value_TEXTURE_NORMAL_OBJ) == self.otherId)
				self->update_matrix = true;
			if (self->value.Value(e_value_SOUND_OBJ) == self.otherId)
				self->value[e_value_SOUND_OBJ] = null_;
			if (self->value_inherit.Value(e_value_SOUND_OBJ) == self.otherId)
				self->update_matrix = true;
			if (self->value.Value(e_value_TEXT_FONT) == self.otherId)
				self->value[e_value_TEXT_FONT] = null_;
			if (self->value_inherit.Value(e_value_TEXT_FONT) == self.otherId)
				self->update_matrix = true;
		}
		
		withOne (app, global::_app->id, self->id)
		{
			if (global::_app->background_image == self.otherId)
				global::_app->background_image = null_;
			if (global::_app->background_sky_sun_tex == self.otherId)
			{
				global::_app->background_sky_sun_tex = global::mc_res;
				idInt(global::_app->background_sky_sun_tex, count)++;
			}
			if (global::_app->background_sky_moon_tex == self.otherId)
			{
				global::_app->background_sky_moon_tex = global::mc_res;
				idInt(global::_app->background_sky_moon_tex, count)++;
			}
			if (global::_app->background_sky_clouds_tex == self.otherId)
			{
				global::_app->background_sky_clouds_tex = global::mc_res;
				idInt(global::_app->background_sky_clouds_tex, count)++;
			}
			if (global::_app->background_ground_tex == self.otherId)
			{
				global::_app->background_ground_tex = global::mc_res;
				idInt(global::_app->background_ground_tex, count)++;
				background_ground_update_texture(ScopeAny(self));
			}
			if (global::_app->background_ground_tex_material == self.otherId)
			{
				global::_app->background_ground_tex_material = global::mc_res;
				idInt(global::_app->background_ground_tex_material, count)++;
				background_ground_update_texture(ScopeAny(self));
			}
			if (global::_app->background_ground_tex_normal == self.otherId)
			{
				global::_app->background_ground_tex_normal = global::mc_res;
				idInt(global::_app->background_ground_tex_normal, count)++;
				background_ground_update_texture_normal(ScopeAny(self));
			}
		}
		
		global::res_edit = sortlist_remove(global::_app->res_list, self->id);
	}
	
	VarType res_get_model_texture(ScopeAny self, VarType name)
	{
		if (!sBool(ready))
			return null_;
		if (sInt(model_texture_map) != null_)
		{
			VarType tex = ds_map_find_value(sInt(model_texture_map), name);
			return is_undefined(tex) ? VarType(null_) : tex;
		}
		else
			return sInt(model_texture);
		
		return VarType();
	}
	
	VarType res_get_model_texture_material(ScopeAny self, VarType name)
	{
		if (!sBool(ready))
			return null_;
		if (sInt(model_texture_material_map) != null_)
		{
			if (ds_map_exists(sInt(model_texture_material_map), name))
				return DsMap(sInt(model_texture_material_map)).Value(name);
			else
				return null_;
			
		}
		else
			if (sInt(model_texture) != null_)
				return sInt(model_texture);
			else
				return null_;
		
		
		return VarType();
	}
	
	VarType res_get_model_tex_normal(ScopeAny self, VarType name)
	{
		if (!sBool(ready))
			return null_;
		if (sInt(model_tex_normal_map) != null_)
		{
			if (ds_map_exists(sInt(model_tex_normal_map), name))
				return DsMap(sInt(model_tex_normal_map)).Value(name);
			else
				return null_;
			
		}
		else
			if (sInt(model_texture) != null_)
				return sInt(model_texture);
			else
				return null_;
		
		
		return VarType();
	}
	
	BoolType res_is_ready(VarType res)
	{
		if (instance_exists(res) && idBool(res, ready))
			return true;
		return false;
	}
	
	void res_load(ScopeAny self, BoolType reload)
	{
		StringType fn = global::load_folder + /*"/"*/ STR(16) + sVar(filename);
		debug({ /*"Loading "*/ STR(2482) + DsList(global::res_type_name_list).Value(sVar(type)), fn });
		switch ((IntType)sVar(type))
		{
			case e_res_type_PACK:
			case e_res_type_PACK_UNZIPPED:
			{
				sBool(ready) = false;
				withOne (app, global::_app->id, self->id)
				{
					ds_priority_add(global::load_queue, self.otherId, IntType(2));
					load_start(ScopeAny(self), self.otherId, ID_res_load_start);
				}
				
				break;
			}
			
			case e_res_type_SKIN:
			case e_res_type_DOWNLOADED_SKIN:
			{
				if (sInt(model_texture) > 0)
					texture_free(sInt(model_texture));
				if (sVar(player_skin) > 0)
					sInt(model_texture) = res_load_player_skin(fn);
				else
					sInt(model_texture) = texture_create_square(fn);
				
				break;
			}
			
			case e_res_type_ITEM_SHEET:
			{
				if (sInt(item_sheet_texture) > 0)
					texture_free(sInt(item_sheet_texture));
				sInt(item_sheet_texture) = texture_create(fn);
				break;
			}
			
			case e_res_type_LEGACY_BLOCK_SHEET:
			case e_res_type_BLOCK_SHEET:
			{
				if (sVar(block_sheet_texture) != null_)
					texture_free(sVar(block_sheet_texture));
				if (sVar(type) == e_res_type_LEGACY_BLOCK_SHEET)
				{
					sVar(block_sheet_texture) = res_load_legacy_block_sheet(fn, global::load_format);
					if (global::load_folder == global::save_folder)
						sVar(filename) = filename_new_ext(filename_name(fn), /*"_converted"*/ STR(2483) + filename_ext(fn));
					texture_export(sVar(block_sheet_texture), global::save_folder + /*"/"*/ STR(16) + sVar(filename));
					sVar(type) = e_res_type_BLOCK_SHEET;
				}
				else
					sVar(block_sheet_texture) = texture_create(fn);
				
				sVar(block_sheet_texture_material) = texture_duplicate(sVar(block_sheet_texture));
				sVar(block_sheet_tex_normal) = texture_duplicate(sVar(block_sheet_texture));
				sInt(colormap_grass_texture) = texture_duplicate(ObjType(obj_resource, global::mc_res)->colormap_grass_texture);
				sInt(colormap_foliage_texture) = texture_duplicate(ObjType(obj_resource, global::mc_res)->colormap_foliage_texture);
				res_update_colors(self);
				res_update_block_preview(Scope<obj_resource>(self));
				break;
			}
			
			case e_res_type_SCENERY:
			case e_res_type_FROM_WORLD:
			{
				StringType cachefn = fn + /*".meshcache"*/ STR(2484);
				if (!reload && file_exists_lib(cachefn) && res_load_block_cache(Scope<obj_resource>(self), cachefn))
					break;
				sBool(ready) = false;
				withOne (app, global::_app->id, self->id)
				{
					ds_priority_add(global::load_queue, self.otherId, IntType(1));
					load_start(ScopeAny(self), self.otherId, ID_res_load_start);
				}
				
				break;
			}
			
			case e_res_type_PARTICLE_SHEET:
			{
				if (sArr(particles_texture).Value(IntType(0)))
					texture_free(sArr(particles_texture).Value(IntType(0)));
				if (sArr(particles_texture).Value(IntType(1)))
					texture_free(sArr(particles_texture).Value(IntType(1)));
				sArr(particles_texture)[IntType(0)] = texture_create_square(fn);
				sArr(particles_texture)[IntType(1)] = sArr(particles_texture).Value(IntType(0));
				break;
			}
			
			case e_res_type_TEXTURE:
			{
				if (sVar(texture) > 0)
					texture_free(sVar(texture));
				sVar(texture) = texture_create(fn);
				break;
			}
			
			case e_res_type_FONT:
			{
				if (font_exists(sInt(font)))
					font_delete(sInt(font));
				if (font_exists(sInt(font_preview)))
					font_delete(sInt(font_preview));
				if (font_exists(sInt(font_no_aa)))
					font_delete(sInt(font_no_aa));
				sInt(font) = font_add_lib({ fn, IntType(48), false, false });
				sInt(font_no_aa) = font_add_lib({ fn, IntType(48), false, false, false });
				sInt(font_preview) = font_add_lib({ fn, IntType(12), false, false });
				if (!(sInt(font) > 0))
				{
					sInt(font) = new_minecraft_font(Scope<obj_resource>(self));
					sInt(font_preview) = new_minecraft_font(Scope<obj_resource>(self));
					sInt(font_no_aa) = new_minecraft_font(Scope<obj_resource>(self));
					sBool(font_minecraft) = true;
				}
				break;
			}
			
			case e_res_type_SOUND:
			{
				audio_stop_all();
				sBool(ready) = false;
				withOne (app, global::_app->id, self->id)
				{
					ds_priority_add(global::load_queue, self.otherId, IntType(0));
					load_start(ScopeAny(self), self.otherId, ID_res_load_start);
				}
				
				break;
			}
			
			case e_res_type_MODEL:
			{
				instance_activate_object(sVar(model_file));
				withOne (Object, sVar(model_file), self->id)
					instance_destroy(self);
				
				if (sInt(model_block_map) != null_)
				{
					VarType key = ds_map_find_first(sInt(model_block_map));
					while (!is_undefined(key))
					{
						vbuffer_destroy(DsMap(sInt(model_block_map)).Value(key));
						key = ds_map_find_next(sInt(model_block_map), key);
					}
					
					ds_map_destroy(sInt(model_block_map));
					sInt(model_block_map) = null_;
				}
				if (sInt(model_texture_map) != null_)
				{
					VarType key = ds_map_find_first(sInt(model_texture_map));
					while (!is_undefined(key))
					{
						texture_free(DsMap(sInt(model_texture_map)).Value(key));
						key = ds_map_find_next(sInt(model_texture_map), key);
					}
					
					ds_map_destroy(sInt(model_texture_map));
					sInt(model_texture_map) = null_;
				}
				if (sInt(model_texture_material_map) != null_)
				{
					VarType key = ds_map_find_first(sInt(model_texture_material_map));
					while (!is_undefined(key))
					{
						texture_free(DsMap(sInt(model_texture_material_map)).Value(key));
						key = ds_map_find_next(sInt(model_texture_material_map), key);
					}
					
					ds_map_destroy(sInt(model_texture_material_map));
					sInt(model_texture_material_map) = null_;
				}
				if (sInt(model_tex_normal_map) != null_)
				{
					VarType key = ds_map_find_first(sInt(model_tex_normal_map));
					while (!is_undefined(key))
					{
						texture_free(DsMap(sInt(model_tex_normal_map)).Value(key));
						key = ds_map_find_next(sInt(model_tex_normal_map), key);
					}
					
					ds_map_destroy(sInt(model_tex_normal_map));
					sInt(model_tex_normal_map) = null_;
				}
				if (filename_ext(fn) == /*".mimodel"*/ STR(710))
				{
					sInt(model_format) = e_model_format_MIMODEL;
					sVar(model_file) = model_file_load({ fn, self->id });
					if (sVar(model_file) == null_)
						error(/*"errorloadmodel"*/ STR(2485));
					if (sInt(model_texture_name_map) != null_)
						ds_map_clear(sInt(model_texture_name_map));
					else
						sInt(model_texture_name_map) = ds_string_map_create();
					
					if (sVar(model_file) != null_)
						DsMap(sInt(model_texture_name_map))[/*""*/ STR(0)] = idVar(sVar(model_file), texture_name);
					if (sInt(model_texture_material_name_map) != null_)
						ds_map_clear(sInt(model_texture_material_name_map));
					else
						sInt(model_texture_material_name_map) = ds_string_map_create();
					
					if (sVar(model_file) != null_)
						DsMap(sInt(model_texture_material_name_map))[/*""*/ STR(0)] = idVar(sVar(model_file), texture_material_name);
					if (sInt(model_tex_normal_name_map) != null_)
						ds_map_clear(sInt(model_tex_normal_name_map));
					else
						sInt(model_tex_normal_name_map) = ds_string_map_create();
					
					if (sVar(model_file) != null_)
						DsMap(sInt(model_tex_normal_name_map))[/*""*/ STR(0)] = idVar(sVar(model_file), texture_normal_name);
					if (sInt(model_color_name_map) != null_)
						ds_map_clear(sInt(model_color_name_map));
					else
						sInt(model_color_name_map) = ds_map_create();
					
					res_update_model_shape(Scope<obj_resource>(self));
					model_shape_update_color(self);
				}
				else
				{
					sInt(model_format) = e_model_format_BLOCK;
					sVar(model_file) = null_;
					sVar(block_vbuffer) = null_;
					VarType blockmodel = block_load_model_file({ fn, self->id });
					if (blockmodel == null_)
					{
						error(/*"errorloadmodel"*/ STR(2485));
						break;
					}
					sInt(model_block_map) = ds_map_create();
					IntType rendermodel = block_load_render_model(self, { blockmodel, vec3(IntType(0)), false, false, IntType(0), self->id });
					block_vbuffer_start(self);
					withOne (obj_builder, global::mc_builder, self->id)
					{
						self->build_size_x = IntType(1);
						self->build_size_y = IntType(1);
						self->build_size_z = IntType(1);
						self->build_randomize = ObjType(obj_resource, self.otherId)->scenery_randomize;
						builder_start(self);
						builder_spawn_threads(self, IntType(1));
						withOne (obj_builder_thread, DsList(self->thread_list).Value(IntType(0)), self->id)
						{
							builder_thread_set_pos(self, IntType(0));
							block_render_model_generate(self, rendermodel);
						}
						
						builder_combine_threads(self);
						builder_done(self);
						self->build_randomize = false;
					}
					
					block_vbuffer_done(self);
					VarType key = ds_map_find_first(sInt(model_block_map));
					while (!is_undefined(key))
					{
						vertex_end((IntType)(DsMap(sInt(model_block_map)).Value(key)));
						DsMap(sInt(model_block_map))[key] = vbuffer_generate_tangents(DsMap(sInt(model_block_map)).Value(key));
						vertex_freeze((IntType)(DsMap(sInt(model_block_map)).Value(key)));
						key = ds_map_find_next(sInt(model_block_map), key);
					}
					
					withOne (obj_block_load_model_file, blockmodel, self->id)
						instance_destroy(ScopeAny(self));
					
				}
				
				break;
			}
			
		}
		
		if (global::load_folder != global::save_folder && sVar(type) != e_res_type_LEGACY_BLOCK_SHEET)
			res_save(self);
		res_update_display_name(Scope<obj_resource>(self));
	}
	
	StringType res_load_browse(ScopeAny self)
	{
		StringType fn;
		switch ((IntType)sVar(type))
		{
			case e_res_type_PACK:
			{
				fn = file_dialog_open_pack();
				break;
			}
			case e_res_type_SCENERY:
			{
				fn = file_dialog_open_scenery();
				break;
			}
			case e_res_type_FONT:
			{
				fn = file_dialog_open_font();
				break;
			}
			case e_res_type_SOUND:
			{
				fn = file_dialog_open_sound();
				break;
			}
			case e_res_type_MODEL:
			{
				fn = file_dialog_open_model();
				break;
			}
			default:
				fn = file_dialog_open_image();
				break;
		}
		
		if (!file_exists_lib(fn))
			return /*""*/ STR(0);
		return fn;
	}
	
	IntType res_load_legacy_block_sheet(StringType fn, VarType format)
	{
		IntType list;
		if (format >= e_project_FORMAT_100_DEMO_2)
			list = global::legacy_block_100_texture_list;
		else
			if (format == e_project_FORMAT_07_DEMO)
				list = global::legacy_block_07_demo_texture_list;
			else
				list = global::legacy_block_05_texture_list;
		
		
		IntType oldtex;
		RealType sheetwid, blocksize;
		oldtex = texture_create(fn);
		sheetwid = IntType(16);
		if (format >= e_project_FORMAT_100_DEMO_2)
			sheetwid = IntType(32);
		blocksize = ceil(texture_width(oldtex) / sheetwid);
		IntType newsurf, newtex;
		newsurf = surface_create((IntType)(block_sheet_width * blocksize), (IntType)(block_sheet_height * blocksize));
		surface_set_target(newsurf);
		draw_clear_alpha(c_black, 0.0);
		gpu_set_blendmode_ext(bm_one, bm_inv_src_alpha);
		draw_texture({ ObjType(obj_resource, global::mc_res)->block_sheet_texture, IntType(0), IntType(0), blocksize / 16.0, blocksize / 16.0 });
		draw_texture_start();
		for (IntType i = IntType(0); i < ds_list_size(list); i++)
		{
			VarType name = DsList(list).Value(i);
			if (name == /*""*/ STR(0))
				continue;
			IntType newindex = ds_list_find_index((IntType)(ObjType(obj_minecraft_assets, global::mc_assets)->block_texture_list), name);
			if (newindex < IntType(0))
			{
				VarType key = ds_map_find_key(global::legacy_block_texture_name_map, name);
				if (is_undefined(key))
				{
					debug({ /*"Could not convert block texture"*/ STR(2490), name });
					continue;
				}
				newindex = ds_list_find_index((IntType)(ObjType(obj_minecraft_assets, global::mc_assets)->block_texture_list), key);
				if (newindex < IntType(0))
				{
					debug({ /*"Could not convert block texture"*/ STR(2490), key });
					continue;
				}
			}
			RealType oldx, oldy, newx, newy;
			oldx = (mod(i, sheetwid)) * blocksize;
			oldy = ((IntType)(i / sheetwid)) * blocksize;
			newx = (mod(newindex, block_sheet_width)) * blocksize;
			newy = ((IntType)(newindex / block_sheet_width)) * blocksize;
			gpu_set_blendmode(bm_subtract);
			draw_blank(newx, newy, blocksize, blocksize);
			gpu_set_blendmode_ext(bm_one, bm_inv_src_alpha);
			draw_texture_part({ oldtex, newx, newy, oldx, oldy, blocksize, blocksize });
		}
		draw_texture_done();
		gpu_set_blendmode(bm_normal);
		surface_reset_target();
		newtex = texture_surface(newsurf);
		surface_free(newsurf);
		return newtex;
	}
	
	RealType res_load_pack(ScopeAny self)
	{
		StringType fname = global::load_folder + /*"/"*/ STR(16) + sVar(filename);
		switch (StringType(sStr(load_stage)).id)
		{
			case 1279: // unzip
			{
				debug({ /*"res_load_pack"*/ STR(2491), /*"unzip"*/ STR(1279) });
				if (sVar(type) != e_res_type_PACK_UNZIPPED)
				{
					if (!unzip({ fname }))
					{
						log({ /*"Error unzipping pack"*/ STR(2492) });
						error(/*"errorunzippack"*/ STR(2493));
						withOne (app, global::_app->id, self->id)
							load_next(ScopeAny(self));
						
						return IntType(0);
					}
				}
				sVar(type) = e_res_type_PACK;
				sStr(load_stage) = /*"modeltextures"*/ STR(1361);
				global::load_assets_dir = unzip_directory;
				res_load_pack_version(self);
				withOne (app, global::_app->id, self->id)
				{
					ObjType(obj_popup, global::_app->popup_loading)->text = text_get({ /*"loadpackmodeltextures"*/ STR(2494) });
					ObjType(obj_popup, global::_app->popup_loading)->progress = 1.0 / 4.0;
				}
				
				break;
			}
			
			case 1361: // modeltextures
			{
				debug({ /*"res_load_pack"*/ STR(2491), /*"modeltextures"*/ STR(1361) });
				res_load_pack_model_textures(self);
				sStr(load_stage) = /*"blocktextures"*/ STR(2495);
				withOne (app, global::_app->id, self->id)
				{
					ObjType(obj_popup, global::_app->popup_loading)->text = text_get({ /*"loadpackblocktextures"*/ STR(2496) });
					ObjType(obj_popup, global::_app->popup_loading)->progress = 2.0 / 4.0;
				}
				
				break;
			}
			
			case 2495: // blocktextures
			{
				debug({ /*"res_load_pack"*/ STR(2491), /*"blocktextures"*/ STR(2495) });
				file_rename_lib(global::load_assets_dir + mc_textures_directory + /*"blocks"*/ STR(994), global::load_assets_dir + mc_textures_directory + /*"block"*/ STR(522));
				res_load_pack_block_textures(self);
				sStr(load_stage) = /*"itemtextures"*/ STR(2497);
				withOne (app, global::_app->id, self->id)
				{
					ObjType(obj_popup, global::_app->popup_loading)->text = text_get({ /*"loadpackitemtextures"*/ STR(2498) });
					ObjType(obj_popup, global::_app->popup_loading)->progress = 3.0 / 4.0;
				}
				
				break;
			}
			
			case 2497: // itemtextures
			{
				debug({ /*"res_load_pack"*/ STR(2491), /*"itemtextures"*/ STR(2497) });
				file_rename_lib(global::load_assets_dir + mc_textures_directory + /*"items"*/ STR(2499), global::load_assets_dir + mc_textures_directory + /*"item"*/ STR(521));
				res_load_pack_item_textures(self, /*"diffuse"*/ STR(621), /*""*/ STR(0));
				res_load_pack_item_textures(self, /*"material"*/ STR(626), /*"_s"*/ STR(2500));
				res_load_pack_item_textures(self, /*"normal"*/ STR(615), /*"_n"*/ STR(2501));
				res_load_pack_particle_textures(self);
				res_load_pack_misc(self);
				res_update_colors(self);
				sBool(ready) = true;
				global::_app->history_resource_update = true;
				log({ /*"Pack loaded"*/ STR(2502) });
				move_all_to_texture_page();
				withAll (obj_template, self->id)
					if (self->item_tex == self.otherId)
						render_generate_item(ScopeAny(self));
				
				withAll (obj_particle_type, self->id)
					if (self->sprite_tex == self.otherId || self->sprite_template_tex == self.otherId)
						ptype_update_sprite_vbuffers(ScopeAny(self));
				
				withOne (obj_bench_settings, global::_app->bench_settings, self->id)
					if (self->item_tex == self.otherId)
						render_generate_item(ScopeAny(self));
				
				withOne (app, global::_app->id, self->id)
				{
					if (global::_app->background_ground_tex == self.otherId)
						background_ground_update_texture(ScopeAny(self));
					if (global::_app->background_ground_tex_material == self.otherId)
						background_ground_update_texture_material(ScopeAny(self));
					if (global::_app->background_ground_tex_normal == self.otherId)
						background_ground_update_texture_normal(ScopeAny(self));
					if (global::_app->background_sky_clouds_tex == self.otherId)
						background_sky_update_clouds(ScopeAny(self));
					load_next(ScopeAny(self));
				}
				
				break;
			}
			
		}
		
		return 0.0;
	}
	
}
