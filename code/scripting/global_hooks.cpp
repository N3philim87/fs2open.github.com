
#include "global_hooks.h"

namespace scripting {
namespace hooks {

const std::shared_ptr<Hook> OnGameInit = Hook::Factory("On Game Init",
	"Executed at the start of the engine after all game data has been loaded.",
	{},
	CHA_GAMEINIT);

const std::shared_ptr<Hook> OnDebrisCreated = Hook::Factory(
	"On Debris Created",
	"Invoked when a piece of debris is created.",
	{
		{"Debris", "debris", "The newly created debris object"},
		{"Source", "object", "The object (probably a ship) from which this debris piece was spawned."},
	});

const std::shared_ptr<OverridableHook> OnShipCollision = OverridableHook::Factory("On Ship Collision",
	"Invoked when a ship collides with another object. Note: When two ships collide this will be called twice, once "
	"with each ship object as the \"Ship\" parameter.",
	{{"Self", "object", "The \"other\" object that collided with the ship."},
		{"Object",
			"ship",
			"The ship object with which the \"other\" object collided with. Provided for consistency with other "
			"collision hooks."},
		{"Ship", "ship", "Same as \"Object\""},
		{"Hitpos", "vector", "The world position where the colission was detected"},
		{"Debris", "object", "The debris object with which the ship collided (only set for debris collisions)"},
		{"Asteroid", "object", "The asteroid object with which the ship collided (only set for asteroid collisions)"},
		{"ShipB", "ship", "For ship on ship collisions, the \"other\" ship."},
		{"Weapon", "weapon", "The weapon object with which the ship collided (only set for weapon collisions)"},
		{"Beam", "weapon", "The beam object with which the ship collided (only set for beam collisions)"}});

const std::shared_ptr<Hook> OnShipDeathStarted = Hook::Factory(
	"On Ship Death Started", "Called when a ship starts the death process.",
	{
		{"Ship", "ship", "The ship that has begun the death process."},
		{"Killer", "object", "The object responsible for killing the ship.  Always set but could be invalid if there is no killer."},
		{"Hitpos", "vector", "The world coordinates of the killing blow.  Could be nil."},
	});

const std::shared_ptr<OverridableHook> OnShipDeath = OverridableHook::Factory(
	"On Ship Death", "Called when a ship has been destroyed.  Supersedes On Death for ships.",
	{
		{"Ship", "ship", "The ship that was destroyed."},
		{"Killer", "object", "The object responsible for killing the ship.  Always set but could be invalid if there is no killer."},
		{"Hitpos", "vector", "The world coordinates of the killing blow.  Could be nil."},
	});

const std::shared_ptr<Hook> OnMissileDeathStarted = Hook::Factory(
	"On Missile Death Started", "Called when a missile is about to be destroyed (whether by impact, interception, or expiration).",
	{
		{"Weapon", "weapon", "The weapon that was destroyed."},
		{"Object", "object", "The object that the weapon hit - a ship, asteroid, or piece of debris.  Always set but could be invalid if there is no other object.  If this missile was destroyed by another weapon, the 'other object' will be invalid but the DestroyedByWeapon flag will be set."},
	});

const std::shared_ptr<Hook> OnMissileDeath = Hook::Factory(
	"On Missile Death", "Called when a missile has been destroyed (whether by impact, interception, or expiration).",
	{
		{"Weapon", "weapon", "The weapon that was destroyed."},
		{"Object", "object", "The object that the weapon hit - a ship, asteroid, or piece of debris.  Always set but could be invalid if there is no other object.  If this missile was destroyed by another weapon, the 'other object' will be invalid but the DestroyedByWeapon flag will be set."},
	});

const std::shared_ptr<Hook> OnAsteroidDeath = Hook::Factory(
	"On Asteroid Death", "Called when an asteroid has been destroyed.  Supersedes On Death for asteroids.",
	{
		{"Asteroid", "asteroid", "The asteroid that was destroyed."},
		{"Hitpos", "vector", "The world coordinates of the killing blow."},
	});

const std::shared_ptr<Hook> OnDebrisDeath = Hook::Factory(
	"On Debris Death", "Called when a piece of debris has been destroyed.",
	{
		{"Debris", "debris", "The piece of debris that was destroyed."},
		{"Hitpos", "vector", "The world coordinates of the killing blow.  Could be nil."},
	});

// ========== DEPRECATED ==========

const std::shared_ptr<OverridableHook> OnDeath = OverridableHook::Factory("On Death",
	"Invoked when an object (ship or asteroid) has been destroyed.  Deprecated in favor of On Ship Destroyed and On Asteroid Destroyed.",
	{
		{"Self", "object", "The object that was killed"},
		{"Ship", "ship", "The ship that was destroyed (only set for ships)"},
		{"Killer", "object", "The object that caused the death (only set for ships)"},
		{"Hitpos",
			"vector",
			"The position of the hit that caused the death (only set for ships and only if available)"},
	});

} // namespace hooks
} // namespace scripting