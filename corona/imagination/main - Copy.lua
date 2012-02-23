require "sprite"
require "physics"

physics.start()

display.setStatusBar(display.HiddenStatusBar)

local leftUnitInstance
local leftUnitSpriteMoving
local leftUnitCombat
local leftUnitCombatinstance
local rightUnitInstance
local rightUnitSpriteMoving
local rightUnitCombat
local rightUnitCombatInstance
local bkgdGroup
local bkgd
local floor
local screenWidth = display.contentWidth
local screenHeight = display.contentHeight
local unitSheet

local function spawnLeft()
	leftUnitSpriteMoving = sprite.newSpriteSet(unitSheet, 2, 4)
	sprite.add(leftUnitSpriteMoving, "leftUnit", 1, 3, 500, 0)
	leftUnitInstance = sprite.newSprite(leftUnitSpriteMoving)
	leftUnitInstance.x = 32
	leftUnitInstance.y = screenHeight*1/2
	leftUnitInstance:prepare("leftUnit")
	leftUnitInstance:play()
	physics.addBody(leftUnitInstance)
end

local function spawnRight()
	rightUnitSpriteMoving = sprite.newSpriteSet(unitSheet, 2, 4)
	sprite.add(rightUnitSpriteMoving, "rightUnit", 1, 3, 500, 0)
	rightUnitInstance = sprite.newSprite(rightUnitSpriteMoving)
	rightUnitInstance.xScale = -1
	rightUnitInstance.x = screenWidth - 32
	rightUnitInstance.y = screenHeight*1/2
	rightUnitInstance:prepare("rightUnit")
	rightUnitInstance:play()
	physics.addBody(rightUnitInstance)
end

local function initializeImages()
	print("Inializing Images...")
	bkgdGroup = display.newGroup()

	bkgd = display.newImage("background.png")
	bkgd:setReferencePoint(display.BottomLeftReferencePoint)
	bkgd.x = 0
	bkgdGroup:insert(bkgd)

	floor = display.newImage("floor.png")
	floor.y = display.contentHeight - floor.contentHeight/2
	floor.name = "floor"
	bkgdGroup:insert(floor)
	physics.addBody(floor, "static")

	unitSheet = sprite.newSpriteSheet("spritesheetv1.png", 64, 64)
	
	spawnLeft()
	
	leftUnitCombat = sprite.newSpriteSet(unitSheet, 5, 2)
	sprite.add(leftUnitCombat, "leftUnitCombat", 1, 2, 10000, 0)
	leftUnitCombatInstance = sprite.newSprite(leftUnitCombat)
	leftUnitCombatInstance.isVisible = false
	
	spawnRight()
	
	rightUnitCombat = sprite.newSpriteSet(unitSheet, 5, 2)
	sprite.add(rightUnitCombat, "rightUnitCombat", 1, 2, 10000, 0)
	rightUnitCombatInstance = sprite.newSprite(rightUnitCombat)
	rightUnitCombatInstance.isVisible = false
	rightUnitCombatInstance.xScale = -1

end



local function onLocalCollision(self, event)
	print("Collision!")
	if (event.other.name == "rightUnitInstance") then
		event.other.isVisible = false;
		event.other:removeSelf()
		self.isVisible = false
		self:removeSelf()
	end

end

local function combatAnimation()
	leftUnitInstance:pause()
	leftUnitInstance.isVisible = false
	rightUnitInstance:pause()
	rightUnitInstance.isVisible = false

	leftUnitCombatInstance:play()
	leftUnitCombatInstance.x = leftUnitInstance.x
	leftUnitCombatInstance.y = leftUnitInstance.y
	leftUnitCombatInstance.isVisible = true
	
	rightUnitCombatInstance:play()
	rightUnitCombatInstance.x = rightUnitInstance.x
	rightUnitCombatInstance.y = rightUnitInstance.y
	rightUnitCombatInstance.isVisible = true
	
	--leftUnitInstance = sprite.newSprite(leftUnitCombatInstance)
end

local function loopAnimations()
	--print("Initializing Animations")
	local function moveLoop()
	if ( rightUnitInstance.x - leftUnitInstance.x > 100) then
		leftUnitInstance.x = leftUnitInstance.x + 5
		rightUnitInstance.x = rightUnitInstance.x - 3
	else
		combatAnimation()
	end
		--transition.to (instance1, {time=5000, x=display.contentWidth})
		--transition.to (instance2, {time=5000, x=0})
		leftUnitInstance.collision = onLocalCollision
--		instance2.collision = onLocalCollision
		
	end
	Runtime:addEventListener( "enterFrame", moveLoop )

end

local function Main()
	print("Running Main()")
	initializeImages()
	loopAnimations()
end
Main()