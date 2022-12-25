from enum import Enum 
import random

class Suite(Enum):
    """花色"""
    SPADE, HEART, CLUB, DIAMOND = range(4)

class Card:

    def __init__(self, suite, face):
        self.suite = suite 
        self.face = face 
    def __repr__(self):
        suites = '♠♥♣♦'
        faces = ['', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
        return f'{suites[self.suite.value]}{faces[self.face]}'

card1 = Card(Suite.SPADE, 5)

class Poker:
    def __init__(self):
        self.cards = [Card(suite, face) for suite in Suite 
                      for face in range(1,14)]
        self.current = 0
    def shuffle(self):
        self.cards = random.shuffle(self.cards)
        self.current = 0
    def deal(self):
        card = self.cards[self.current]
        self.current += 1
        return card 




