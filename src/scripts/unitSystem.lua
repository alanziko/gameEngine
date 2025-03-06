function unitSystem()
    local mousePosition = getMousePosition(eventMapEntity)
    local leftMouseButton = getLeftMouseButtonState(eventMapEntity)
    local units = getEntitiesByComponent("Position")

    for _, unit in pairs(units) do
        local unitPos = getPosition(unit)
        local globalX = unitPos[1]*TILE_SIZE
        local globalY = unitPos[2]*TILE_SIZE+MAP_Y_OFFSET
        if (mousePosition[1] >= globalX and mousePosition[1] <= globalX+TILE_SIZE) then
            if (mousePosition[2] >= globalY and mousePosition[2] <= globalY+TILE_SIZE) then
                if(leftMouseButton) then
                    setSelectedUnit(unit)
                end
            end
        end
    end
end 