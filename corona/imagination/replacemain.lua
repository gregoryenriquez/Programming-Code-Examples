require "sprite"
require "physics"

physics.start()
display.setStatusBar(display.HiddenStatusBar)

--Global unit variables
local unit
local unitMovingSet
local unitFightingSet
local unitSheet

--Global scene
local background
local grpBackground
local floor

--Global constants
local screenWidth = display.contentWidth
local screenHeight = display.contentHeight
local animationTime = 500

--Global positioning
local leftSide = 0
local rightSide = screenWidth


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
end

local function initSheets()
	print("Initializing sprite sheets...")
	unitSheet = sprite.newSpriteSheet("spritesheetv1.png", 64, 64)
end

local function initUnits()
	print("Initializing unit sprites")
	unitMovingSet = sprite.newSpriteSet(unitSheet, 2, 4)
	sprite.add(unitMovingSet, "unitMoving", 1, 3, 500, 0)
	unitMoving = sprite.newSprite(unitMovingSet)
	unitMoving.isVisible = false
	
	unitFightingSet = sprite.newSpriteSet(unitSheet, 5, 2)
	sprite.add(unitFightingSet, "unitCombat", 1, 2, 1000, 0)
	unitFighting = sprite.newSprite(unitFightingSet)
	unitMoving.isVisible = false
end

local function initSprites()
	print("Initializing sprites...")
	initSheets()
	initUnits()
end

local function init()
	print("Initializing...")
	initBackground()
	initSprites()
end

local function spawnTest()
	print("SPAWN TEST")
	--unitMoving = sprite.newSprite(unitMovingSet)
	unitMoving.isVisible = true
	unitMoving.x = 32
	unitMoving.y = screenHeight*1/2
	unitMoving:prepare("unitMoving")
	unitMoving:play()
	physics.addBody(unitMoving)
end

local function loopAnimations()
	local function moveLoop()
		unitMoving.x = unitMoving.x + 1
	end
	Runtime:addEventListener( "enterFrame", moveLoop )
end

local function Main()
	print("Initializing Main...")
	init()
	spawnTest()
	loopAnimations()
end

Main()