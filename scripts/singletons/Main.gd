extends Control

onready var editor_warning_dialog = $HBoxContainer/Body/Pages/EditorGUI/WarningDialog
onready var editor = $Editor
onready var editor_page = $HBoxContainer/Sidebar/VBoxContainer/TopContainer/Editor
onready var home_page = $HBoxContainer/Sidebar/VBoxContainer/TopContainer/Home
onready var window_title = $HBoxContainer/Body/TopBar/TitleBar/Heading

func _ready():
	if !KeEngine.project_loaded:
		home_page.set_active()
	else:
		$BG.visible = false
		editor.editor_is_active = true
		editor_page.set_active()

func _process(_delta):
	window_title.text = "Kingdom Engine - " + KeEngine.current_page
	#verifica se o Editor esta ativo e controla o aviso
	if editor:
		if editor.editor_is_active:
			editor_warning_dialog.visible = false
		else:
			editor_warning_dialog.visible = true
