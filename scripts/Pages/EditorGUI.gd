extends Control

onready var main_bg = $"../../../../BG"
onready var editor = $"../../../../Editor"

func _on_EditorGUI_visibility_changed():
	if main_bg and editor.editor_is_active:
		main_bg.visible = !visible
		$LockBG.visible = !visible
