extends Node

func run_game(name: String, width: int, height: int):
	var path = "bin/Engine.exe"
	var args = [name, width, height]
	var process = OS.execute(path, args, false)
	
	if process == 0:
		printerr("Erro ao executar o Jogo")
