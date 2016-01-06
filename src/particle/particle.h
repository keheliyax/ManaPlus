/*
 *  The ManaPlus Client
 *  Copyright (C) 2006-2009  The Mana World Development Team
 *  Copyright (C) 2009-2010  The Mana Developers
 *  Copyright (C) 2011-2016  The ManaPlus Developers
 *
 *  This file is part of The ManaPlus Client.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PARTICLE_PARTICLE_H
#define PARTICLE_PARTICLE_H

#include "being/actor.h"

#include "enums/particle/alivestatus.h"

#include "localconsts.h"

class Color;
class Font;
class Particle;
class ParticleEmitter;

typedef std::list<Particle *> Particles;
typedef Particles::iterator ParticleIterator;
typedef Particles::const_iterator ParticleConstIterator;
typedef std::list<ParticleEmitter *> Emitters;
typedef Emitters::iterator EmitterIterator;
typedef Emitters::const_iterator EmitterConstIterator;

/**
 * A particle spawned by a ParticleEmitter.
 */
class Particle notfinal : public Actor
{
    public:
        static const float PARTICLE_SKY;  // Maximum Z position of particles
        static int fastPhysics;           // Mode of squareroot calculation
        static int particleCount;         // Current number of particles
        static int maxCount;              // Maximum number of particles
        static int emitterSkip;           // Duration of pause between two
                                          // emitter updates in ticks
        static bool enabled;  // true when non-crucial particle effects
                              // are disabled

        Particle();

        A_DELETE_COPY(Particle)

        /**
         * Destructor.
         */
        virtual ~Particle();

        /**
         * Deletes all child particles and emitters.
         */
        void clear() restrict2;

        /**
         * Gives a particle the properties of an engine root particle and loads
         * the particle-related config settings.
         */
        void setupEngine() restrict2;

        /**
         * Updates particle position, returns false when the particle should
         * be deleted.
         */
        virtual bool update() restrict2;

        /**
         * Draws the particle image.
         */
        virtual void draw(Graphics *restrict const graphics,
                          const int offsetX,
                          const int offsetY) const restrict2 override
                          A_CONST A_NONNULL(2);

        /**
         * Necessary for sorting with the other sprites.
         */
        int getPixelY() const restrict2 override A_WARN_UNUSED
        { return static_cast<int>(mPos.y) - 16; }

        /**
         * Necessary for sorting with the other sprites for sorting only.
         */
        int getSortPixelY() const restrict2 override A_WARN_UNUSED
        { return static_cast<int>(mPos.y) - 16; }

        /**
         * Creates a blank particle as a child of the current particle
         * Useful for creating target particles
         */
        Particle *createChild() restrict2;

        /**
         * Creates a child particle that hosts some emitters described in the
         * particleEffectFile.
         */
        Particle *addEffect(const std::string &restrict particleEffectFile,
                            const int pixelX, const int pixelY,
                            const int rotation = 0) restrict2;

        /**
         * Creates a standalone text particle.
         */
        Particle *addTextSplashEffect(const std::string &restrict text,
                                      const int x, const int y,
                                      const Color *restrict const color,
                                      Font *restrict const font,
                                      const bool outline = false) restrict2;

        /**
         * Creates a standalone text particle.
         */
        Particle *addTextRiseFadeOutEffect(const std::string &restrict text,
                                           const int x, const int y,
                                           const Color *restrict const color,
                                           Font *restrict const font,
                                           const bool outline = false)
                                           restrict2;

        /**
         * Adds an emitter to the particle.
         */
        void addEmitter(ParticleEmitter *const emitter) restrict2
        { mChildEmitters.push_back(emitter); }

        /**
         * Sets the position in 3 dimensional space in pixels relative to map.
         */
        void moveTo(const Vector &restrict pos) restrict2
        { moveBy(pos - mPos); }

        /**
         * Sets the position in 2 dimensional space in pixels relative to map.
         */
        void moveTo(const float x, const float y) restrict2;

        /**
         * Changes the particle position relative
         */
        void moveBy(const Vector &restrict change) restrict2;

        /**
         * Sets the time in game ticks until the particle is destroyed.
         */
        void setLifetime(const int lifetime) restrict2 noexcept
        { mLifetimeLeft = lifetime; mLifetimePast = 0; }

        /**
         * Sets the age of the pixel in game ticks where the particle has
         * faded in completely.
         */
        void setFadeOut(const int fadeOut) restrict2 noexcept
        { mFadeOut = fadeOut; }

        /**
         * Sets the remaining particle lifetime where the particle starts to
         * fade out.
         */
        void setFadeIn(const int fadeIn) restrict2 noexcept
        { mFadeIn = fadeIn; }

        /**
         * Sets the current velocity in 3 dimensional space.
         */
        void setVelocity(const float x,
                         const float y,
                         const float z) restrict2 noexcept
        { mVelocity.x = x; mVelocity.y = y; mVelocity.z = z; }

        /**
         * Sets the downward acceleration.
         */
        void setGravity(const float gravity) restrict2 noexcept
        { mGravity = gravity; }

        /**
         * Sets the ammount of random vector changes
         */
        void setRandomness(const int r) restrict2 noexcept
        { mRandomness = r; }

        /**
         * Sets the ammount of velocity particles retain after
         * hitting the ground.
         */
        void setBounce(const float bouncieness) restrict2 noexcept
        { mBounce = bouncieness; }

        /**
         * Sets the flag if the particle is supposed to be moved by its parent
         */
        void setFollow(const bool follow) restrict2 noexcept
        { mFollow = follow; }

        /**
         * Gets the flag if the particle is supposed to be moved by its parent
         */
        bool doesFollow() const restrict2 noexcept A_WARN_UNUSED
        { return mFollow; }

        /**
         * Makes the particle move toward another particle with a
         * given acceleration and momentum
         */
        void setDestination(Particle *restrict const target,
                            const float accel,
                            const float moment) restrict2 noexcept
        { mTarget = target; mAcceleration = accel; mMomentum = moment; }

        /**
         * Sets the distance in pixel the particle can come near the target
         * particle before it is destroyed. Does only make sense after a target
         * particle has been set using setDestination.
         */
        void setDieDistance(const float dist) restrict2
        { mInvDieDistance = 1.0F / dist; }

        /**
         * Changes the size of the emitters so that the effect fills a
         * rectangle of this size
         */
        void adjustEmitterSize(const int w, const int h) restrict2;

        void setAllowSizeAdjust(const bool adjust) restrict2 noexcept
        { mAllowSizeAdjust = adjust; }

        bool isAlive() const restrict2 noexcept A_WARN_UNUSED
        { return mAlive == AliveStatus::ALIVE; }

        void prepareToDie() restrict2;

        /**
         * Determines whether the particle and its children are all dead
         */
        bool isExtinct() const restrict2 noexcept A_WARN_UNUSED
        { return !isAlive() && mChildParticles.empty(); }

        /**
         * Manually marks the particle for deletion.
         */
        void kill() restrict2 noexcept
        { mAlive = AliveStatus::DEAD_OTHER; mAutoDelete = true; }

        /**
         * After calling this function the particle will only request
         * deletion when kill() is called
         */
        void disableAutoDelete() restrict2 noexcept
        { mAutoDelete = false; }

        /** We consider particles (at least for now) to be one layer-sprites */
        int getNumberOfLayers() const restrict2 override final
        { return 1; }

        float getAlpha() const restrict2 override final
        { return 1.0F; }

        void setAlpha(const float alpha A_UNUSED) restrict2 override
        { }

        virtual void setDeathEffect(const std::string &restrict effectFile,
                                    const signed char conditions) restrict2
        { mDeathEffect = effectFile; mDeathEffectConditions = conditions; }

    protected:
        // Opacity of the graphical representation of the particle
        float mAlpha;

        // Lifetime left in game ticks
        int mLifetimeLeft;

        // Age of the particle in game ticks
        int mLifetimePast;

        // Lifetime in game ticks left where fading out begins
        int mFadeOut;

        // Age in game ticks where fading in is finished
        int mFadeIn;

        // Speed in pixels per game-tick.
        Vector mVelocity;

        // Is the particle supposed to be drawn and updated?
        AliveStatusT mAlive;
    private:
        // List of child emitters.
        Emitters mChildEmitters;

        // List of particles controlled by this particle
        Particles mChildParticles;

        // Particle effect file to be spawned when the particle dies
        std::string mDeathEffect;

        // dynamic particle
        // Downward acceleration in pixels per game-tick.
        float mGravity;

        // How much the particle bounces off when hitting the ground
        float mBounce;

        // Acceleration towards the target particle in pixels per game-tick
        float mAcceleration;

        // Distance in pixels from the target particle that causes
        // the destruction of the particle
        float mInvDieDistance;

        // How much speed the particle retains after each game tick
        float mMomentum;

        // The particle that attracts this particle
        Particle *restrict mTarget;

        // Ammount of random vector change
        int mRandomness;

        // Bitfield of death conditions which trigger spawning
        // of the death particle
        signed char mDeathEffectConditions;

        // May the particle request its deletion by the parent particle?
        bool mAutoDelete;

        // Can the effect size be adjusted by the object props in the map file?
        bool mAllowSizeAdjust;

        // is this particle moved when its parent particle moves?
        bool mFollow;
};

extern Particle *particleEngine;

#endif  // PARTICLE_PARTICLE_H
