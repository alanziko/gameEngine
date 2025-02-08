function movementSystem(registry)
    local entities = getEntitiesByComponent("Position")
    local position = getPosition(entities[1])
    for k, v in pairs(position)
    do
        setPosition(entities[1], k, v+10)
    end
end