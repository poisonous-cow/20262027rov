local BUTTON_FUNCTION_1 = 1
local BUTTON_FUNCTION_2 = 2

function update()
	if sub:is_button_pressed(BUTTON_FUNCTION_1) then
		gpio:write(12, 1)
		gpio:write(13, 0)
	elseif sub:is_button_pressed(BUTTON_FUNCTION_2) then
        	gpio:write(12, 0)
        	gpio:write(13, 1)
	else
		gpio:write(12, 0)
		gpio:write(13, 0)
	end

	return update, 0
end

return update()


