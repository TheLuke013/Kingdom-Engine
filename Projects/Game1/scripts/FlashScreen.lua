local bg_color = {0, 0, 0, 0}

function Start()
    Engine.window_set_vsync(false)
    Engine.window_set_title("Piscando loucamente a tela")
end

function Update()
    --gera numeros aleatorios de 1 a 255 e atribui ao bg_color
    bg_color[0] = math.random(1, 255)
    bg_color[1] = math.random(1, 255)
    bg_color[2] = math.random(1, 255)
    bg_color[3] = math.random(1, 255)

    Engine.window_set_bg_color(bg_color)
end