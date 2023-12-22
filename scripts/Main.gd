extends Control

onready var editor_warning_dialog = $HBoxContainer/Body/Pages/EditorGUI/WarningDialog

func _process(_delta):
	#verifica se o Editor esta ativo e controla o aviso
	if $Editor.editor_is_active:
		editor_warning_dialog.visible = false
	else:
		editor_warning_dialog.visible = true
