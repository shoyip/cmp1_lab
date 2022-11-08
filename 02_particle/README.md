# Particle

## Goal

Simulate the decay of a particle to two lower mass particles and assess
the impact of the detector resolution on the measured invariant mass of
the particles.

## Features

- [x] Generate a data sample with $10^4$ events
- [x] In each event a B meson decays to a pion and a kaon. In the center
        of mass of the B meson, the decay products have momentum $p^*$
        and their direction is random.
- [x] Boost the momentum of the pion and the kaon to the lab reference frame,
        in this reference frame compute the invariant mass of pion and kaon
        and the opening angle between the kaon and the pion and fill a histogram
- [ ] Perform *smearing*

## Design

## Compilation and Use

The program can be compiled in the following manner

```console
$ g++ -o particle particle.cpp `root-config --libs --cflags`
```

and can be subsequently run as follows

```console
$ ./particle
```

This will generate three new files:

- `data/particle.root`, which contains the `TTree` object with the generated data
- `figures/invariant_mass.pdf`, which contains the histogram of the invariant mass of $\pi$ and $K$
- `figures/collision_angle.pdf`, which contains the histogram for the opening angle between $\pi$ and $K$
