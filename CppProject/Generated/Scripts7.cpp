/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.12.26 22:36:37 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	void action_lib_shape_tex_hmirror(ScopeAny self, VarType hmirror)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_hmirror, idVar(global::temp_edit, shape_tex_hmirror), hmirror, false);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_hmirror) = hmirror;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_tex_hoffset(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_hoffset, idVar(global::temp_edit, shape_tex_hoffset), idVar(global::temp_edit, shape_tex_hoffset) * add + val, true);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_hoffset) = sVar(shape_tex_hoffset) * add + val;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_tex_hrepeat(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_hrepeat, idVar(global::temp_edit, shape_tex_hrepeat), idVar(global::temp_edit, shape_tex_hrepeat) * add + val, true);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_hrepeat) = sVar(shape_tex_hrepeat) * add + val;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_tex_mapped(ScopeAny self, VarType map)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_mapped, idVar(global::temp_edit, shape_tex_mapped), map, false);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_mapped) = map;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	RealType action_lib_shape_tex_material(ScopeAny self, IntType res)
	{
		StringType fn;
		fn = /*""*/ STR(0);
		if (sReal(history_undo) > 0)
			res = history_undo_res();
		else
			if (sReal(history_redo) > 0)
				res = history_redo_res(self);
			else
			{
				if (res == e_option_BROWSE)
				{
					fn = file_dialog_open_image();
					if (!file_exists_lib(fn))
						return IntType(0);
					res = new_res(self, fn, e_res_type_TEXTURE);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_lib_shape_tex_material, fn, idVar(global::temp_edit, shape_tex_material), res);
			}
		
		
		withOne (Object, global::temp_edit, self->id)
		{
			if (sVar(shape_tex_material) != null_)
				idInt(sVar(shape_tex_material), count)--;
			sVar(shape_tex_material) = res;
			if (sVar(shape_tex_material) != null_ && idVar(sVar(shape_tex_material), type) != e_tl_type_CAMERA)
				idInt(sVar(shape_tex_material), count)++;
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		return 0.0;
	}
	
	RealType action_lib_shape_tex_normal(ScopeAny self, IntType res)
	{
		StringType fn;
		fn = /*""*/ STR(0);
		if (sReal(history_undo) > 0)
			res = history_undo_res();
		else
			if (sReal(history_redo) > 0)
				res = history_redo_res(self);
			else
			{
				if (res == e_option_BROWSE)
				{
					fn = file_dialog_open_image();
					if (!file_exists_lib(fn))
						return IntType(0);
					res = new_res(self, fn, e_res_type_TEXTURE);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_lib_shape_tex_normal, fn, idVar(global::temp_edit, shape_tex_normal), res);
			}
		
		
		withOne (Object, global::temp_edit, self->id)
		{
			if (sVar(shape_tex_normal) != null_)
				idInt(sVar(shape_tex_normal), count)--;
			sVar(shape_tex_normal) = res;
			if (sVar(shape_tex_normal) != null_ && idVar(sVar(shape_tex_normal), type) != e_tl_type_CAMERA)
				idInt(sVar(shape_tex_normal), count)++;
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		return 0.0;
	}
	
	void action_lib_shape_tex_vmirror(ScopeAny self, VarType vmirror)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_vmirror, idVar(global::temp_edit, shape_tex_vmirror), vmirror, false);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_vmirror) = vmirror;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_tex_voffset(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_voffset, idVar(global::temp_edit, shape_tex_voffset), idVar(global::temp_edit, shape_tex_voffset) * add + val, true);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_voffset) = sVar(shape_tex_voffset) * add + val;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_tex_vrepeat(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_vrepeat, idVar(global::temp_edit, shape_tex_vrepeat), idVar(global::temp_edit, shape_tex_vrepeat) * add + val, true);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_vrepeat) = sVar(shape_tex_vrepeat) * add + val;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_text_3d(ScopeAny self, VarType is3d)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_text_3d, idVar(global::temp_edit, text_3d), is3d, false);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(text_3d) = is3d;
			temp_update_rot_point(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_text_face_camera(ScopeAny self, VarType face)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_text_face_camera, idVar(global::temp_edit, text_face_camera), face, false);
		idVar(global::temp_edit, text_face_camera) = face;
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	RealType action_lib_text_font(ScopeAny self, IntType res)
	{
		StringType fn;
		fn = /*""*/ STR(0);
		if (sReal(history_undo) > 0)
			res = history_undo_res();
		else
			if (sReal(history_redo) > 0)
				res = history_redo_res(self);
			else
			{
				if (res == e_option_BROWSE)
				{
					fn = file_dialog_open_font();
					if (!file_exists_lib(fn))
						return IntType(0);
					res = new_res(self, fn, e_res_type_FONT);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_lib_text_font, fn, idVar(global::temp_edit, text_font), res);
			}
		
		
		withOne (Object, global::temp_edit, self->id)
		{
			if (sVar(text_font) != null_)
				idInt(sVar(text_font), count)--;
			sVar(text_font) = res;
			idInt(sVar(text_font), count)++;
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		return 0.0;
	}
	
	void action_project_grid_columns(ScopeAny self, VarType val, VarType add)
	{
		sVar(project_grid_columns) = sVar(project_grid_columns) * add + val;
	}
	
	void action_project_grid_rows(ScopeAny self, VarType val, VarType add)
	{
		sVar(project_grid_rows) = sVar(project_grid_rows) * add + val;
	}
	
	void action_project_render_aa(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_aa, sVar(project_render_aa), enable, true);
		sVar(project_render_aa) = enable;
	}
	
	void action_project_render_aa_power(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_aa_power, sVar(project_render_aa_power), sVar(project_render_aa_power) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_aa_power) = sVar(project_render_aa_power) * add + val / 100.0;
	}
	
	void action_project_render_alpha_mode(ScopeAny self, VarType mode)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_alpha_mode, sVar(project_render_alpha_mode), mode, IntType(1));
		sVar(project_render_alpha_mode) = mode;
		global::render_samples = -IntType(1);
	}
	
	void action_project_bend_style(ScopeAny self, VarType style)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_bend_style, sVar(project_bend_style), style, IntType(1));
		sVar(project_bend_style) = style;
		global::render_samples = -IntType(1);
		withAll (obj_timeline, self->id)
		{
			self->bend_rot_last = vec3(IntType(0));
			tl_update_model_shape_bend(ScopeAny(self));
		}
		
	}
	
	void action_project_render_block_emissive(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_block_emissive, sVar(project_render_block_emissive), sVar(project_render_block_emissive) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_block_emissive) = sVar(project_render_block_emissive) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_block_subsurface(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_block_subsurface, sVar(project_render_block_subsurface), sVar(project_render_block_subsurface) * add + val, IntType(1));
		sVar(project_render_block_subsurface) = sVar(project_render_block_subsurface) * add + val;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_distance(ScopeAny self, VarType val, VarType add)
	{
		sVar(project_render_distance) = sVar(project_render_distance) * add + val;
	}
	
	RealType action_project_render_export(ScopeAny self, StringType fn)
	{
		if (fn == /*""*/ STR(0))
			fn = file_dialog_save_render(/*""*/ STR(0));
		if (fn == /*""*/ STR(0))
			return IntType(0);
		project_save_start(fn, false);
		project_save_render(self);
		project_save_done();
		log({ /*"Saved render settings"*/ STR(11), fn });
		toast_new(self, e_toast_POSITIVE, text_get({ /*"alertrendersaved"*/ STR(12) }));
		return 0.0;
	}
	
	void action_project_render_exposure(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_exposure, sVar(project_render_exposure), sVar(project_render_exposure) * add + val, IntType(1));
		sVar(project_render_exposure) = sVar(project_render_exposure) * add + val;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_gamma(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_gamma, sVar(project_render_gamma), sVar(project_render_gamma) * add + val, IntType(1));
		sVar(project_render_gamma) = sVar(project_render_gamma) * add + val;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_glint_speed(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glint_speed, sVar(project_render_glint_speed), sVar(project_render_glint_speed) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_glint_speed) = sVar(project_render_glint_speed) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_glint_strength(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glint_strength, sVar(project_render_glint_strength), sVar(project_render_glint_strength) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_glint_strength) = sVar(project_render_glint_strength) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_glow(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow, sVar(project_render_glow), enable, true);
		sVar(project_render_glow) = enable;
	}
	
	void action_project_render_glow_falloff(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow_falloff, sVar(project_render_glow_falloff), enable, true);
		sVar(project_render_glow_falloff) = enable;
	}
	
	void action_project_render_glow_falloff_intensity(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow_falloff_intensity, sVar(project_render_glow_falloff_intensity), sVar(project_render_glow_falloff_intensity) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_glow_falloff_intensity) = sVar(project_render_glow_falloff_intensity) * add + val / 100.0;
	}
	
	void action_project_render_glow_falloff_radius(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow_falloff_radius, sVar(project_render_glow_falloff_radius), sVar(project_render_glow_falloff_radius) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_glow_falloff_radius) = sVar(project_render_glow_falloff_radius) * add + val / 100.0;
	}
	
	void action_project_render_glow_intensity(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow_intensity, sVar(project_render_glow_intensity), sVar(project_render_glow_intensity) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_glow_intensity) = sVar(project_render_glow_intensity) * add + val / 100.0;
	}
	
	void action_project_render_glow_radius(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_glow_radius, sVar(project_render_glow_radius), sVar(project_render_glow_radius) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_glow_radius) = sVar(project_render_glow_radius) * add + val / 100.0;
	}
	
	RealType action_project_render_import(ScopeAny self, StringType fn)
	{
		if (sReal(history_undo) > 0)
			history_copy_render_settings(self, ObjType(obj_history, global::history_data)->save_obj_old);
		else
			if (sReal(history_redo) > 0)
				history_copy_render_settings(self, ObjType(obj_history, global::history_data)->save_obj_new);
			else
			{
				if (fn == /*""*/ STR(0))
					fn = file_dialog_open_render();
				if (fn == /*""*/ STR(0))
					return IntType(0);
				IntType map = project_load_start(fn);
				if (map == null_)
					return IntType(0);
				VarType hobj;
				if (sArr(history).Value(IntType(0)) != null_ && ObjType(obj_history, sArr(history).Value(IntType(0)))->script == ID_action_project_render_settings)
					hobj = sArr(history).Value(IntType(0));
				else
					hobj = history_set(self, ID_action_project_render_import);
				
				ObjType(obj_history, hobj)->save_obj_old = (new obj_history_save)->id;
				ObjType(obj_history_save, ObjType(obj_history, hobj)->save_obj_old)->hobj = hobj;
				ObjType(obj_history, hobj)->save_obj_new = (new obj_history_save)->id;
				ObjType(obj_history_save, ObjType(obj_history, hobj)->save_obj_new)->hobj = hobj;
				ObjType(obj_history, hobj)->fn = fn;
				withOne (obj_history_save, ObjType(obj_history, hobj)->save_obj_old, self->id)
					history_copy_render_settings(ScopeAny(self), global::_app->id);
				
				project_load_render(self, DsMap(map).Value(/*"render"*/ STR(13)));
				ds_map_destroy(map);
				withOne (obj_history_save, ObjType(obj_history, hobj)->save_obj_new, self->id)
					history_copy_render_settings(ScopeAny(self), global::_app->id);
				
				log({ /*"Loaded render settings"*/ STR(14), fn });
			}
		
		
		return 0.0;
	}
	
	void action_project_render_indirect(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_indirect, sVar(project_render_indirect), enable, true);
		sVar(project_render_indirect) = enable;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_indirect_blur_radius(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_indirect_blur_radius, sVar(project_render_indirect_blur_radius), sVar(project_render_indirect_blur_radius) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_indirect_blur_radius) = sVar(project_render_indirect_blur_radius) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_indirect_precision(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_indirect_precision, sVar(project_render_indirect_precision), sVar(project_render_indirect_precision) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_indirect_precision) = sVar(project_render_indirect_precision) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_indirect_strength(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_indirect_strength, sVar(project_render_indirect_strength), sVar(project_render_indirect_strength) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_indirect_strength) = sVar(project_render_indirect_strength) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_liquid_animation(ScopeAny self, VarType value)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_liquid_animation, sVar(project_render_liquid_animation), value, IntType(1));
		sVar(project_render_liquid_animation) = value;
		toast_new(self, e_toast_WARNING, text_get({ /*"alertreloadobjects"*/ STR(15) }));
	}
	
	void action_project_render_material_maps(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_material_maps, sVar(project_render_material_maps), enable, IntType(1));
		sVar(project_render_material_maps) = enable;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_opaque_leaves(ScopeAny self, VarType value)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_opaque_leaves, sVar(project_render_opaque_leaves), value, true);
		sVar(project_render_opaque_leaves) = value;
		toast_new(self, e_toast_WARNING, text_get({ /*"alertreloadobjects"*/ STR(15) }));
	}
	
	void action_project_render_open_image_denoise(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_open_image_denoise, sVar(project_render_open_image_denoise), enable, true);
		sVar(project_render_open_image_denoise) = enable;
	}
	
	void action_project_render_open_image_denoise_usediffuse(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_open_image_denoise_usediffuse, sReal(project_render_open_image_denoise_usediffuse), enable, true);
		sReal(project_render_open_image_denoise_usediffuse) = enable;
	}
	
	void action_project_render_open_image_denoise_usenormals(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_open_image_denoise_usenormals, sReal(project_render_open_image_denoise_usenormals), enable, true);
		sReal(project_render_open_image_denoise_usenormals) = enable;
	}
	
	void action_project_render_pass(ScopeAny self, VarType pass)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_pass, sInt(project_render_pass), pass, IntType(1));
		sInt(project_render_pass) = pass;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_reflections(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_reflections, sVar(project_render_reflections), enable, IntType(1));
		sVar(project_render_reflections) = enable;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_reflections_fade_amount(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_reflections_fade_amount, sVar(project_render_reflections_fade_amount), sVar(project_render_reflections_fade_amount) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_reflections_fade_amount) = sVar(project_render_reflections_fade_amount) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_reflections_precision(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_reflections_precision, sVar(project_render_reflections_precision), sVar(project_render_reflections_precision) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_reflections_precision) = sVar(project_render_reflections_precision) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_reflections_thickness(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_reflections_thickness, sVar(project_render_reflections_thickness), sVar(project_render_reflections_thickness) * add + val, IntType(1));
		sVar(project_render_reflections_thickness) = sVar(project_render_reflections_thickness) * add + val;
		global::render_samples = -IntType(1);
	}
	
	RealType action_project_render_reset(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
			history_copy_render_settings(self, ObjType(obj_history, global::history_data)->save_obj_old);
		else
		{
			if (!(sReal(history_redo) > 0))
			{
				if (!question(text_get({ /*"questionresetrender"*/ STR(16) })))
					return IntType(0);
				IntType hobj = history_set(self, ID_action_project_render_reset);
				ObjType(obj_history, hobj)->save_obj_old = (new obj_history_save)->id;
				ObjType(obj_history_save, ObjType(obj_history, hobj)->save_obj_old)->hobj = hobj;
				withOne (obj_history_save, ObjType(obj_history, hobj)->save_obj_old, self->id)
					history_copy_render_settings(ScopeAny(self), global::_app->id);
				
			}
			project_reset_render(self);
		}
		
		return 0.0;
	}
	
	void action_project_render_samples(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_samples, sVar(project_render_samples), sVar(project_render_samples) * add + val, IntType(1));
		VarType valold = sVar(project_render_samples);
		sVar(project_render_samples) = sVar(project_render_samples) * add + val;
		if (sVar(project_render_samples) < valold)
			global::render_samples = -IntType(1);
	}
	
	RealType action_project_render_settings(ScopeAny self, VarType file)
	{
		if (sReal(history_undo) > 0)
		{
			file = ObjType(obj_history, global::history_data)->oldval;
			if (ObjType(obj_history, global::history_data)->save_obj_old != null_)
				history_copy_render_settings(self, ObjType(obj_history, global::history_data)->save_obj_old);
		}
		else
			if (sReal(history_redo) > 0)
			{
				file = ObjType(obj_history, global::history_data)->newval;
				if (ObjType(obj_history, global::history_data)->save_obj_new != null_)
					history_copy_render_settings(self, ObjType(obj_history, global::history_data)->save_obj_new);
			}
			else
			{
				if (file == /*""*/ STR(0) && global::trial_version > 0)
				{
					popup_show(self, sInt(popup_upgrade));
					ObjType(obj_popup, sInt(popup_upgrade))->page = IntType(2);
					ObjType(obj_popup, sInt(popup_upgrade))->custom_rendering = file;
					return IntType(0);
				}
				IntType hobj = history_set(self, ID_action_project_render_settings);
				ObjType(obj_history, hobj)->oldval = sVar(project_render_settings);
				ObjType(obj_history, hobj)->newval = file;
				ObjType(obj_history, hobj)->save_obj_new = null_;
				ObjType(obj_history, hobj)->save_obj_old = null_;
			}
		
		
		sVar(project_render_settings) = file;
		if (sVar(project_render_settings) != /*""*/ STR(0))
		{
			if (!(sReal(history_redo) > 0) && !(sReal(history_undo) > 0))
				action_project_render_import(self, render_directory + sVar(project_render_settings) + /*".mirender"*/ STR(17));
		}
		return 0.0;
	}
	
	void action_project_render_shadows(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_shadows, sVar(project_render_shadows), enable, IntType(1));
		sVar(project_render_shadows) = enable;
		global::render_samples = -IntType(1);
	}
	
	RealType action_project_render_shadows_point_buffer_size(ScopeAny self, VarType size)
	{
		if (size >= IntType(4096))
			if (!question(text_get({ /*"questionbuffersizewarning"*/ STR(18) })))
				return IntType(0);
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_shadows_point_buffer_size, sVar(project_render_shadows_point_buffer_size), size, IntType(1));
		sVar(project_render_shadows_point_buffer_size) = size;
		global::render_samples = -IntType(1);
		return 0.0;
	}
	
	RealType action_project_render_shadows_spot_buffer_size(ScopeAny self, VarType size)
	{
		if (size >= IntType(8192))
			if (!question(text_get({ /*"questionbuffersizewarning"*/ STR(18) })))
				return IntType(0);
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_shadows_spot_buffer_size, sVar(project_render_shadows_spot_buffer_size), size, IntType(1));
		sVar(project_render_shadows_spot_buffer_size) = size;
		global::render_samples = -IntType(1);
		return 0.0;
	}
	
	RealType action_project_render_shadows_sun_buffer_size(ScopeAny self, VarType size)
	{
		if (size >= IntType(8192))
			if (!question(text_get({ /*"questionbuffersizewarning"*/ STR(18) })))
				return IntType(0);
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_shadows_sun_buffer_size, sVar(project_render_shadows_sun_buffer_size), size, IntType(1));
		sVar(project_render_shadows_sun_buffer_size) = size;
		global::render_samples = -IntType(1);
		return 0.0;
	}
	
	void action_project_render_shadows_transparent(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_shadows_transparent, sVar(project_render_shadows_transparent), enable, IntType(1));
		sVar(project_render_shadows_transparent) = enable;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_ssao(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_ssao, sVar(project_render_ssao), enable, IntType(1));
		sVar(project_render_ssao) = enable;
	}
	
	void action_project_render_ssao_color(ScopeAny self, VarType color)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_ssao_color, sVar(project_render_ssao_color), color, IntType(1));
		sVar(project_render_ssao_color) = color;
	}
	
	void action_project_render_ssao_power(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_ssao_power, sVar(project_render_ssao_power), sVar(project_render_ssao_power) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_ssao_power) = sVar(project_render_ssao_power) * add + val / 100.0;
	}
	
	void action_project_render_ssao_radius(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_ssao_radius, sVar(project_render_ssao_radius), sVar(project_render_ssao_radius) * add + val, IntType(1));
		sVar(project_render_ssao_radius) = sVar(project_render_ssao_radius) * add + val;
	}
	
	void action_project_render_subsurface_highlight(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_subsurface_highlight, sVar(project_render_subsurface_highlight), sVar(project_render_subsurface_highlight) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_subsurface_highlight) = sVar(project_render_subsurface_highlight) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_subsurface_highlight_strength(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_subsurface_highlight_strength, sVar(project_render_subsurface_highlight_strength), sVar(project_render_subsurface_highlight_strength) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_subsurface_highlight_strength) = sVar(project_render_subsurface_highlight_strength) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_subsurface_samples(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_subsurface_samples, sVar(project_render_subsurface_samples), sVar(project_render_subsurface_samples) * add + val, IntType(1));
		sVar(project_render_subsurface_samples) = sVar(project_render_subsurface_samples) * add + val;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_texture_filtering(ScopeAny self, VarType filtering)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_texture_filtering, sVar(project_render_texture_filtering), filtering, IntType(1));
		sVar(project_render_texture_filtering) = filtering;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_texture_filtering_level(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_texture_filtering_level, sVar(project_render_texture_filtering_level), sVar(project_render_texture_filtering_level) * add + val, IntType(1));
		sVar(project_render_texture_filtering_level) = sVar(project_render_texture_filtering_level) * add + val;
		global::render_samples = -IntType(1);
		texture_set_mipmap_level(sVar(project_render_texture_filtering_level));
	}
	
	void action_project_render_tonemapper(ScopeAny self, VarType tonemapper)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_tonemapper, sVar(project_render_tonemapper), tonemapper, IntType(1));
		sVar(project_render_tonemapper) = tonemapper;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_transparent_block_texture_filtering(ScopeAny self, VarType filtering)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_transparent_block_texture_filtering, sVar(project_render_transparent_block_texture_filtering), filtering, IntType(1));
		sVar(project_render_transparent_block_texture_filtering) = filtering;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_water_reflections(ScopeAny self, VarType value)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_water_reflections, sVar(project_render_water_reflections), value, IntType(1));
		sVar(project_render_water_reflections) = value;
	}
	
	void action_project_tempo(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_tempo, sVar(project_tempo), sVar(project_tempo) * add + val, IntType(1));
		sVar(project_tempo) = sVar(project_tempo) * add + val;
		tl_update_length();
	}
	
	RealType action_project_video_height(ScopeAny self, RealType val, VarType add)
	{
		RealType ratio;
		if (sReal(history_undo) > 0)
		{
			sVar(project_video_width) = ObjType(obj_history, global::history_data)->old_width;
			sVar(project_video_height) = ObjType(obj_history, global::history_data)->old_height;
			return IntType(0);
		}
		else
			if (sReal(history_redo) > 0)
				val = ObjType(obj_history, global::history_data)->new_height;
			else
			{
				VarType hobj;
				history_pop(self);
				if (sReal(history_amount) > IntType(0) && ObjType(obj_history, sArr(history).Value(IntType(0)))->script == ID_action_project_video_height)
					hobj = sArr(history).Value(IntType(0));
				else
				{
					history_push(self);
					hobj = new_history(ID_action_project_video_height);
					ObjType(obj_history, hobj)->old_width = sVar(project_video_width);
					ObjType(obj_history, hobj)->old_height = sVar(project_video_height);
				}
				
				ObjType(obj_history, hobj)->new_height = sVar(project_video_height) * add + val;
				sArr(history)[IntType(0)] = hobj;
			}
		
		
		ratio = (RealType)sVar(project_video_width) / sVar(project_video_height);
		sVar(project_video_height) = sVar(project_video_height) * add + val;
		if (sVar(project_video_keep_aspect_ratio) > 0)
			sVar(project_video_width) = max({ IntType(1), round(sVar(project_video_height) * ratio) });
		return 0.0;
	}
	
	void action_project_video_keep_aspect_ratio(ScopeAny self)
	{
		sVar(project_video_keep_aspect_ratio) = !(sVar(project_video_keep_aspect_ratio) > 0);
	}
	
	RealType action_project_video_template(ScopeAny self, VarType argument0)
	{
		if (sReal(history_undo) > 0)
		{
			sVar(project_video_template) = ObjType(obj_history, global::history_data)->oldtemplate;
			sVar(project_video_width) = ObjType(obj_history, global::history_data)->oldwidth;
			sVar(project_video_height) = ObjType(obj_history, global::history_data)->oldheight;
			return IntType(0);
		}
		else
			if (sReal(history_redo) > 0)
				argument0 = ObjType(obj_history, global::history_data)->newtemplate;
			else
			{
				IntType hobj = history_set(self, ID_action_project_video_template);
				ObjType(obj_history, hobj)->oldtemplate = sVar(project_video_template);
				ObjType(obj_history, hobj)->newtemplate = argument0;
				ObjType(obj_history, hobj)->oldwidth = sVar(project_video_width);
				ObjType(obj_history, hobj)->oldheight = sVar(project_video_height);
			}
		
		
		sVar(project_video_template) = argument0;
		if (sVar(project_video_template) > IntType(0))
		{
			sVar(project_video_width) = ObjType(obj_videotemplate, sVar(project_video_template))->width;
			sVar(project_video_height) = ObjType(obj_videotemplate, sVar(project_video_template))->height;
		}
		return 0.0;
	}
	
	RealType action_project_video_width(ScopeAny self, RealType val, VarType add)
	{
		RealType ratio;
		if (sReal(history_undo) > 0)
		{
			sVar(project_video_width) = ObjType(obj_history, global::history_data)->old_width;
			sVar(project_video_height) = ObjType(obj_history, global::history_data)->old_height;
			return IntType(0);
		}
		else
			if (sReal(history_redo) > 0)
				val = ObjType(obj_history, global::history_data)->new_width;
			else
			{
				VarType hobj;
				history_pop(self);
				if (sReal(history_amount) > IntType(0) && ObjType(obj_history, sArr(history).Value(IntType(0)))->script == ID_action_project_video_width)
					hobj = sArr(history).Value(IntType(0));
				else
				{
					history_push(self);
					hobj = new_history(ID_action_project_video_width);
					ObjType(obj_history, hobj)->old_width = sVar(project_video_width);
					ObjType(obj_history, hobj)->old_height = sVar(project_video_height);
				}
				
				ObjType(obj_history, hobj)->new_width = sVar(project_video_width) * add + val;
				sArr(history)[IntType(0)] = hobj;
			}
		
		
		ratio = (RealType)sVar(project_video_width) / sVar(project_video_height);
		sVar(project_video_width) = sVar(project_video_width) * add + val;
		if (sVar(project_video_keep_aspect_ratio) > 0)
			sVar(project_video_height) = max({ IntType(1), round((RealType)sVar(project_video_width) / ratio) });
		return 0.0;
	}
	
	void action_recent_pin(VarType item)
	{
		idVar(item, pinned) = !(idVar(item, pinned) > 0);
		global::_app->recent_list_update = true;
	}
	
	void action_recent_remove(VarType item)
	{
		idBool(item, remove) = true;
		global::_app->recent_list_update = true;
	}
	
	void action_recent_sort(ScopeAny self, VarType sort)
	{
		sVar(recent_sort_mode) = sort;
		recent_update(self);
	}
	
	RealType action_load_render_settings(ScopeAny self, StringType fn)
	{
		IntType map = project_load_start(fn);
		if (map == null_)
			return IntType(0);
		project_load_render(self, DsMap(map).Value(/*"render"*/ STR(13)));
		ds_map_destroy(map);
		return 0.0;
	}
	
	RealType action_restore_controls(ScopeAny self)
	{
		if (!question(text_get({ /*"questionrestorecontrols"*/ STR(19) })))
			return IntType(0);
		keybinds_reset_default(self);
		sReal(setting_move_speed) = IntType(1);
		sReal(setting_look_sensitivity) = IntType(1);
		sReal(setting_fast_modifier) = IntType(3);
		sReal(setting_slow_modifier) = 0.25;
		return 0.0;
	}
	
	RealType action_res_export(ScopeAny self)
	{
		if (idVar(global::res_edit, type) == e_res_type_PACK)
		{
			VarType fn = file_dialog_save_image(filename_get_valid(idVar(global::res_edit, display_name)));
			if (fn == /*""*/ STR(0))
				return IntType(0);
			fn = filename_new_ext(fn, /*".png"*/ STR(10));
			texture_export(ObjType(obj_preview, sInt(res_preview))->texture, fn);
		}
		else
		{
			StringType ext;
			VarType fn;
			ext = filename_ext(idVar(global::res_edit, filename));
			fn = file_dialog_save_resource(filename_get_valid(idVar(global::res_edit, display_name)), ext);
			if (fn == /*""*/ STR(0))
				return IntType(0);
			fn = filename_new_ext(fn, ext);
			global::load_folder = sStr(project_folder);
			global::save_folder = filename_dir(fn);
			withOne (Object, global::res_edit, self->id)
			{
				res_save(self);
				file_rename_lib(global::save_folder + /*"/"*/ STR(20) + sVar(filename), fn);
			}
			
		}
		
		return 0.0;
	}
	
}
