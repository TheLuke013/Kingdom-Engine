extends Control

onready var main_bg = $"../../../../BG"
onready var editor = $"../../../../Editor"

func _on_EditorGUI_visibility_changed():
	if main_bg and editor:
		main_bg.visible = !visible
		editor.editor_is_active = visible
	
