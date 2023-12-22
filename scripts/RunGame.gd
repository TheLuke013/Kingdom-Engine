extends Node

func run_game():
	var path = "bin/Engine.exe"
	var args = []
	var process = OS.execute(path, args, false)
	
	if process == 0:
		printerr("Erro ao executar o Jogo")
