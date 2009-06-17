/*
 * This file is part of NumptyPhysics
 * Copyright (C) 2008 Tim Edmonds
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 */
#include "Event.h"


BasicEventMap::BasicEventMap( const KeyPair* keys, const ButtonPair* buttons )
  : m_keys(keys), m_buttons(buttons)
{}

Event BasicEventMap::process(const SDL_Event& ev)
{
  switch (ev.type) {
  case SDL_MOUSEBUTTONDOWN: {
    const ButtonPair* inf = lookupButton(ev.button.button);
    if (inf) return Event(inf->down, ev.button.x, ev.button.y);;
    break; }
  case SDL_MOUSEBUTTONUP: {
    const ButtonPair* inf = lookupButton(ev.button.button);
    if (inf) return Event(inf->up, ev.button.x, ev.button.y);
    break; }
  case SDL_MOUSEMOTION: {
    const ButtonPair* inf = lookupButton(ev.button.button);
    if (inf) return Event(inf->move, ev.button.x, ev.button.y);
    break; }
  case SDL_KEYDOWN: {
    const KeyPair* inf = lookupKey(ev.key.keysym.sym);
    if (inf) return Event(inf->ev, (char)ev.key.keysym.unicode);
    break; }
  }
}

const BasicEventMap::KeyPair*
BasicEventMap::lookupKey(SDLKey sym)
{
  const KeyPair* p = m_keys;
  while (p && p->sym) {
    if (p->sym == sym) return p;
    p++;
  }
  return NULL;
}

const BasicEventMap::ButtonPair*
BasicEventMap::lookupButton(uint8_t button)
{
  const ButtonPair* p = m_buttons;
  while (p && p->button) {
    if (p->button == button) return p;
    p++;
  }
  return NULL;
}

