extends ColorRect

enum TYPES {close, maximize, minimize}

export(TYPES) var types = TYPES.close
export(StreamTexture) var icon

func _ready():
	$Icon.texture = icon

func _on_SysButton_gui_input(event):
	if event is InputEventMouseButton:
		if event.is_pressed() and event.get_button_index() == 1:
			if types == TYPES.close:
				get_tree().quit()
			elif types == TYPES.minimize:
				OS.window_minimized = true
			elif types == TYPES.maximize:
				OS.set_window_maximized(!OS.window_maximized)

func _on_SysButton_mouse_entered():
	if types == TYPES.close:
		color = "#f03333"
	else:
		color = "#4c3575"

func _on_SysButton_mouse_exited():
	color = "#7858a6"
