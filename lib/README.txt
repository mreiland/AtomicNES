This lib folder is generally meant for 3rd party dependencies.  These dependencies will never be checked into source control or distributed with AtomicNES.  While this may seem incovenient, it's not nearly as inconvenient as being trapped to an older version of a library (I'm looking at you spdlog with your usage of fmt...)

lib/header-only is for exactly what it says.

DEPENDENCIES
  HEADER ONLY
    doctest
    
  CMAKE BASED -- cd into the root of the project.
    fmt -- git clone https://github.com/fmtlib/fmt.git lib/fmt;


    
Eventually this should all be scripted/automated.
