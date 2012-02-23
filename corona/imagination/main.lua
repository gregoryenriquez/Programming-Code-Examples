require "sprite"
require "physics"
local widget = require "widget"

physics.start()
--physics.setGravity(0, 9)
physics.setDrawMode("hybrid")
display.setStatusBar(display.HiddenStatusBar)

--Global unit variables
local unit
local unitMovingSet
local unitFightingSet
local unitSheet
local text

--Global direction
local direction

--Global scene
local menu
local grpMenu
local background
local grpBackground
local floor
local hill

--Global constants
local screenWidth = display.contentWidth
local screenHeight = display.contentHeight
local animationTime = 500

--Global positioning
local leftSide = 0
local rightSide = screenWidth

--Widgets n buttons!
local btnSpawn

local function createUnit (self, name, hp, direction)
	self.name = name
	self.hp = hp
	self.direction = direction
	return self
end

local onButtonEvent  = function(event)
		if (event.phase == "release") then
		print("spawn!")
		spawnTest()
	end
end

local function initButtons()
	btnSpawn = widget.newButton{
		id = "btn001",
		left = 0,
		top = screenHeight/2,
		label = "Widget Button",
		width = 150, height = 28,
		cornerRadius = 8,
		onEvent = onButtonEvent 
	}
end

local function initBackground()
	print("Initializing background...")
	grpBackground = display.newGroup()
	background = display.newImage("background.png")
	background:setReferencePoint(display.BottomLeftReferencePoint)
	background.x = 0
	grpBackground:insert(background)
	
	floor = display.newImage("floor.png")
	floor.y = screenHeight - floor.contentHeight/2
	floor.name = "floor"
	grpBackground:insert(floor)
	physics.addBody(floor, "static")
	
	initButtons()
end

local function initSheets()
	print("Initializing sprite sheets...")
	unitSheet = sprite.newSpriteSheet("spritesheetv1.png", 64, 64)
end

local function initUnits()
	print("Initializing unit sprites")
	unitMovingSet = sprite.newSpriteSet(unitSheet, 2, 4)
	sprite.add(unitMovingSet, "unitMoving", 1, 3, 500, 0)
	--unitMoving = sprite.newSprite(unitMovingSet)
	--unitMoving.isVisible = false
	
	unitFightingSet = sprite.newSpriteSet(unitSheet, 5, 2)
	sprite.add(unitFightingSet, "unitCombat", 1, 2, 1000, 0)
	--unitFighting = sprite.newSprite(unitFightingSet)
	--unitFighting.isVisible = false
	
end

local function initSprites()
	print("Initializing sprites...")
	initSheets()
	initUnits()
end

--[[
local function moveLoop(self)
	if (self.direction == "left") then
		self.x = self.x + 1
	else 
		self.x = self.x - 1
	end
end
--]]

local function inCombat(self, event)
	
	if (event.other.name == "rightUnit" and self.inCombat == false) then 
	print("combat!")
		self:pause()
		event.other:pause()
		self.inCombat = true
		combatLoop = function()
		--[[
			if (event.other.hp < 0) then
				print("unit death!")
				--event.other:removeEventListener("enterFrame", moveLoop)
				event.other:removeSelf()
			end
		--]]
			if (event.other.hp >= 1) then
				event.other.hp = event.other.hp - 50
				local text = display.newText("-50", event.other.x, event.other.y-20, nil, 12)
				--grpBackground:insert(text)
				text:setTextColor(0, 0, 0)
				text:toFront()
				transition.to(text, {time = 1000, alpha = 0, y=event.other.y})
			end
		end
		timer.performWithDelay(1000, combatLoop, 0)
		--Runtime:addEventListener( "enterFrame", combatLoop )
	end
end

local function spawn(direction)
	--local function createUnit (self, name, hp, direction)
	local movingSprite = sprite.newSprite(unitMovingSet)
	local unitTemp = movingSprite
	unitTemp.direction = direction
	
--	local moveLoop
	if (unitTemp.direction == "left") then
		unitTemp = createUnit(unitTemp, "leftUnit", 100, "left")
	--	unitTemp = sprite.newSprite(unitMovingSet)
		unitTemp.x = 32
		unitTemp.y = screenHeight*1/2
--		unitTemp.name = "leftUnit"
		moveLoop = function() 
			if (unitTemp ~= nil and unitTemp.hp <= 0) then
				print("unit death!")
				Runtime:removeEventListener( "enterFrame", moveLoop)
				unitTemp:removeEventListener( "collision", unitTemp )
				unitTemp:removeSelf()
				unitTemp = nil
			else
				unitTemp.x = unitTemp.x + 1
			end
		end
	else 
		unitTemp = createUnit(unitTemp, "rightUnit", 100, "right")
	--	unitTemp = sprite.newSprite(unitMovingSet)
		unitTemp.xScale = - 1
		unitTemp.x = screenWidth - 32
		unitTemp.y = screenHeight*1/2
--		unitTemp.name = "rightUnit"
		moveLoop = function() 
			if (unitTemp ~= nil and unitTemp.hp <= 0) then
				print("unit death!")
				Runtime:removeEventListener( "enterFrame", moveLoop)
				unitTemp:removeEventListener( "collision", unitTemp )
				unitTemp:removeSelf()
				unitTemp = nil
			else
				unitTemp.x = unitTemp.x - 1
			end
		end
	end

		unitTemp.inCombat = false
		unitTemp.collision = inCombat
		unitTemp:addEventListener( "collision", unitTemp)
		Runtime:addEventListener( "enterFrame", moveLoop)

	
		unitTemp:prepare("unitMoving")
		unitTemp:play()
		physics.addBody(unitTemp)
end

function spawnTest()
	print("SPAWN TEST")
	--unitMoving = sprite.newSprite(unitMovingSet)
	--[[unitMoving.isVisible = true
	unitMoving.x = 32
	unitMoving.y = screenHeight*1/2
	unitMoving:prepare("unitMoving")
	unitMoving:play()
	physics.addBody(unitMoving)
	--]]
	direction = "left"
	spawn(direction)
	direction = "right"
	spawn(direction)
	--loopAnimations()
end

local function tween(event)
	if (event.target.name == "touchtostart" ) then
		print("Going to game screen")
		transition.to(background, {time = 10000, y = -menu.height, 
		transition = easing.inOutExpo, onComplete = initBackground(), spawnTest() })
		text.isVisible = false
	end
end

local function initMenu()
	print("Initializing Menu...")
	grpBackground = display.newGroup()
	menu = display.newImage("mainmenu.png")
	--grpBackground:insert(menu)
	
	text = display.newText("Touch to start", 0, 0, nil, 16)
--	grpMenu:insert(text)
	text:setTextColor(0, 0, 0)
	text.name = "touchtostart"
	text.x = screenWidth/2
	text.y = screenHeight/2
	
	text:addEventListener('tap', tween)
	
end

local function init()
	print("Initializing...")
	--initBackground()
	initMenu()
	initSprites()
end





--[[
local function loopAnimations()
	local function moveLoop()
		unitMoving.x = unitMoving.x + 1
	end
	Runtime:addEventListener( "enterFrame", moveLoop )
end
--]]
local function Main()
	print("Initializing Main...")
	init()
	--spawnTest()
	--loopAnimations()
end

Main()