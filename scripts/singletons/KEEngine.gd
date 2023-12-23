extends Node

var project_loaded = false

func load_project():
	project_loaded = true
	var reload_engine = get_tree().reload_current_scene()
	return reload_engine
