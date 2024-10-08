/// app_startup_collapse()

function app_startup_collapse()
{
	globalvar collapse_map, collapse_ani, collapse_groups;
	collapse_ani = 1
	collapse_groups = 0
	
	collapse_map = ds_map_create()
	
	collapse_register("backup")
	collapse_register("watermark")
	
	collapse_register("uiappearance")
	collapse_register("uitimeline")
	collapse_register("uitools")
	collapse_register("uiviewport")
	
	collapse_register("bindsfile")
	collapse_register("bindsedit")
	collapse_register("bindstools")
	collapse_register("bindsviewport")
	collapse_register("bindstimeline")
	collapse_register("bindscamera")
	
	collapse_register("texfilter")
	
	collapse_register("ssao")
	collapse_register("shadows")
	collapse_register("subsurface")
	collapse_register("indirect")
	collapse_register("reflections")
	collapse_register("glow")
	collapse_register("glow_falloff")
	collapse_register("aa")
	collapse_register("light_management")
	collapse_register("models_scenery")
	collapse_register("glint")
	collapse_register("openimagedenoise")
	
	collapse_register("sunlight")
	collapse_register("sky")
	collapse_register("clouds")
	collapse_register("ground")
	collapse_register("fog")
	collapse_register("wind")
	
	collapse_register("follow_path")
	collapse_register("rotatepoint")
	collapse_register("ik")
	collapse_register("copyrot")
	collapse_register("lookat")
	collapse_register("childof")
	collapse_register("copypos")
	collapse_register("copyscale")
	collapse_register("bendik")
	
	collapse_register("light_management_cam")
	collapse_register("aperture")
	collapse_register("camshake")
	collapse_register("dof")
	collapse_register("dof_fringe")
	collapse_register("bloom")
	collapse_register("lensdirt")
	collapse_register("clrcor")
	collapse_register("grain")
	collapse_register("vignette")
	collapse_register("ca")
	collapse_register("distort")
	
	collapse_register("itemslot")
	
	collapse_register("material_color")
	collapse_register("material_surface")
	collapse_register("material_subsurface")
	
	collapse_register("textoutline")
	
	collapse_register("tl_glint")
}
