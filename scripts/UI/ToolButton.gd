extends ColorRect

enum TYPES {run}

export(TYPES) var types = TYPES.run
export(StreamTexture) var icon

func _ready():
	$Icon.texture = icon
