extends ColorRect

enum TYPES {close, maximize, minimize}

export(TYPES) var types = TYPES.close
export(StreamTexture) var icon

var maximized: bool
var default_width = 1024
var default_height = 600

func _ready():
	$Icon.texture = icon

func maximize_window():
	var width = OS.get_screen_size().x
	var height = OS.get_screen_size().y
	
	OS.set_window_size(Vector2(width - 2, height- 2))
	OS.set_window_position(Vector2(0, 0))
	maximized = true

func minimize_window():
	OS.set_window_size(Vector2(default_width, default_height))
	maximized = false

func _on_SysButton_gui_input(event):
	if event is InputEventMouseButton:
		if event.is_pressed() and event.get_button_index() == 1:
			if types == TYPES.close:
				get_tree().quit()
			elif types == TYPES.minimize:
				OS.window_minimized = true
			elif types == TYPES.maximize:
				if maximized:
					minimize_window()
				else:
					maximize_window()

func _on_SysButton_mouse_entered():
	if types == TYPES.close:
		color = "#f03333"
	else:
		color = "#4c3575"

func _on_SysButton_mouse_exited():
	color = "#7858a6"
