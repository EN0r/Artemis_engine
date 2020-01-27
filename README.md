# Artemis Engine v0.03

This engine is very buggy but it does not utilize much memory and has near to no memory leaks. Due to this early in development there will be bugs which you can see in the #WARNINGS section


## Instructions

1. Install it.
2. Open it in visual studio 2019(Or anything with c++ 17 support)
3. Code it to your needs.
4. Compile!

## Documentation

With this engine the current features it has is: an ECS system, Low memory usage on rendering sprites, Animation flipbooks.
To utilize the ECS you need to create a new `_system` object. With this system object you can add components by using the
`_System->addComponent<COMPONENTTYPE>(entityToAddTo,ComponentObject);` with this function you can add a component to the entity and to
get the component you can use `COMPONENTTYPE component = _System->getComponent<COMPONENTTYPE>(entityToAddTo,ComponentObject)`

## WARNING

This engine is very early in development and you WILL experience bugs with this, Eventually the bugs will be sweeped out and new components will be added to the engine.

Also, the GUI Library will be deprecated soon. I will post a update on this soon.
