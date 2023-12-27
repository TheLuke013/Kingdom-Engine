extends Node

var project_loaded = false
var current_page = ""
var current_project_name = "No Project"
var current_project_data

func load_project():
	project_loaded = true
	var reload_engine = get_tree().reload_current_scene()
	return reload_engine
