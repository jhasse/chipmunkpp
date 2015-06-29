#include <iostream>
#include <iomanip>
#include <chipmunk.hpp>

using namespace cp;
using namespace std;

int main() {
    // cp::Vect is a 2D vector.
    Vect gravity(0, -100);

    // Create an empty space.
    Space space;
    space.setGravity(gravity);

    // Add a static line segment shape for ground.
    // We'll make it slightly tilted so the ball will roll off.
    // We attach it to space.staticBody to tell Chipmunk it shouldn't be movable.
    auto ground = make_shared<SegmentShape>(space.staticBody,
                                            Vect(-20, 5), Vect(20, -5), 0);
    ground->setFriction(1);
    space.add(ground);

    // Now let's make a ball that falls onto the line and rolls off.
    // First we need to make a Body to hold the physical properties of the object.
    // These include the mass, position, velocity, angle, etc. of the object.
    // Then we attach collision shapes to the cpBody to give it a size and shape.

    const Float radius = 5;
    const Float mass = 1;

    // The moment of inertia is like mass for rotation
    // Use the cp::momentFor*() functions to help you approximate it.
    const Float moment = momentForCircle(mass, 0, radius);

    auto ballBody = make_shared<Body>(mass, moment);
    space.add(ballBody);
    ballBody->setPosition(Vect(0, 15));

    // Now we create the collision shape for the ball.
    // You can create multiple collision shapes that point to the same body.
    // They will all be attached to the body and move arount to follow it.
    auto ballShape = make_shared<CircleShape>(ballBody, radius);
    space.add(ballShape);
    ballShape->setFriction(0.7);

    // Now that it's all set up, we simulate all the objects in the space by
    // stepping forward through time in small increments called steps.
    // It is *highly* recommended to use a fixed size time step.
    Float timeStep = 1.0/60.0;
    for (Float time = 0; time < 2; time += timeStep) {
        Vect pos = ballBody->getPosition();
        Vect vel = ballBody->getVelocity();
        cout << setprecision(2) << fixed
             << "Time is "          << setw(5) << time << ". "
             << "ballBody is at "   << setw(5) << pos << ". "
             << "It's velocity is " << setw(5) << vel << endl;
        space.step(timeStep);
    }
}
