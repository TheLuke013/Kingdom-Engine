local number = 0

function Start()
end

function Update()
    number = number + 1
    print(number)
    if number == 100 then
        Engine.ChangeScene("Main")
    end
end