function movementSystem(registry)
    local entities = getEntitiesByComponent("Position")
    for i = 1,#entities,1
    do
        print(i)
        setPosition(entities[i], 0, 0)
    end
end