extends Control

onready var main_bg = $"../../../../BG"
onready var editor = $"../../../../Editor"
onready var lock_bg = $LockBG

func _on_EditorGUI_visibility_changed():
	if main_bg and editor.editor_is_active:
		main_bg.visible = !visible
		lock_bg.visible = !visible
	
	#muda o titulo da janela para o nome da pagina
	if visible:
		KeEngine.current_page = "Editor: " + KeEngine.current_project_name
