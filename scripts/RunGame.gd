extends Node

var python_script_path = ProjectSettings.globalize_path("res://tasks/run_game.py")

func run_game():
	var process = OS.execute("python", [python_script_path])
	
	if process != 0:
		printerr("Erro ao executar o Jogo")
