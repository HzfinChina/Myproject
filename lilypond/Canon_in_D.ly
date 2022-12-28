\version "2.24.0"
\header {
  title = "Pachelbel's Canon (Canon in D)"
  composer = "Johann Pachelbel"
}

{
  \new PianoStaff <<

    \new Staff \relative{\tempo 4=65 \time 4/4 \key d \major 
    fis''2\pp e
    d cis
    b a
    b cis
    <fis d> <e cis> \break
    <d b> <cis a> 
    <b g> <a fis>
    <b g> <cis a>\<  \bar "||"\! 
    <<
      \fixed c'' {
    fis e
    fis, a, \break
    b, a,
    g, e,4 e,
      }
      \fixed c''{
    d8 cis d fis, e, a, g, e,
    d d cis b, cis fis a b \break
    g fis e g fis e d cis
    b, a, b, d d4 cis
      }
    >> \bar "||" 
    a'8\mp fis16 g a8 fis16 g a a, b cis d e fis g
    fis8 d16 e fis8 fis,16 g a b a g a fis g a \break
    g8 b16 a g8 fis16 e fis e d e fis g a b
    g8 b16 a b8 cis16 d cis b a b cis\> d e fis\!
    <g fis>8 <fis d>16 <g d> <a fis>8 <fis d>16 <g e> <a cis,> a, b cis d e fis g \break
    <fis d>8\mp <d b>16 <e cis> <fis d>8 fis,16 g <a fis> b a g a d cis d
    <b g>8 <d b>16 <cis a> <b g>8 b16 g <a fis> g fis g a b cis d
    <b g>8\p <d b>16 <cis a> <d b>8 cis16 b cis\<  d e d cis d b cis\! \bar "||" \break
    <<{
    a'4 fis8 a a b a g
    fis4 d8 fis fis g fis e
    d4 b8 d d4 fis,8 d'
    d c b c cis2 \break 
    a'4 fis8 a a b a g
    fis4 d8 fis fis g fis e
    d4 b8 d d4 fis,8 d' \break 
    d8 c b c cis4 d8 e
    }\\ 
    {
    fis2 e4 cis 
    d2 cis4 a 
    b2 a4 s4
    g2\> a |\!
    fis'2 e4 cis 
    d2 cis4 a
    b2 a4 s4
    g2 a\> |\!
    }
    >> \bar "||"
    fis'4\mf <d d'>8 fis fis g <cis fis, cis> e,
    d4 <b b'>8 d d e <a a, d> cis, \break
    b4 <g g'> <fis' d'> <d a'>
    <b' d,> <g b,> <a cis,> <fis fis,>8\< <g g,> |\! 
    \bar "||"
    a16\> a, d fis a fis d a\! a'\< a, b' g, a' a, g' g,\! \break 
    fis'\> fis, b d fis d b fis\! fis'\< fis, g' g, fis' fis, fis' e,\!
    d'\< d, g b d b g d d' d, fis a fis' fis, a d\!
    g\> g, b d b' b, d g\!  a\< a, cis e b' b, cis' cis,\! \break 
    d'\f d, fis a d a fis d d' d, e a cis cis, e a 
    cis cis, d fis b b, d fis b b, cis fis a a, cis fis \break
    a a, b d g g, b d g g, a d fis fis, a d
    fis fis, g b e e, g' g, a'\> a, cis e <b' b,>8 <cis cis,>\!\break 
    <d a fis d>4\mf <d, a fis> <cis a e cis>8. <e cis'>16 a e cis e 
    <b' fis d b>4 <b, fis d> <a fis cis a>8. <a' cis,>16 fis cis a cis \break 
    <g' d b g>4 <g, d b g> <fis d a fis> <fis' d a fis> 
    <g, d b g> <b' g d b> <cis, a e cis>8 <e cis a e> <a e cis a> <cis a e cis>
    <fis d fis,>1\arpeggio\> |\!
    r2 \ottava 1<d' d,>2\arpeggio\fermata
    \bar "|."
  }
  \new Staff \relative c{\time 4/4 \key d \major \clef "bass"
    d8(\sustainOn a' d fis) a,,(\sustainOn e' a cis) 
    b,\sustainOn( fis' b d) fis,,\sustainOn( cis' fis a)
    g,\sustainOn( d' g b) d,,( a' d fis)
    g,( d' g b) a,( e' a cis)
    d,( a' d fis) a,,( e' a cis)
    b,( fis' b d) fis,,( cis' fis a)
    g,( d' g b) d,,( a' d fis)
    g,( d' g b) a,( e' a cis)
    d,( a' d a) a,( e' a e)
    b( fis' b fis) fis,( cis' fis cis)\break
    g( d' g d) d,( a' d a)
    g( d' g d) a( e' a e)
    d( a' d a) a,( e' a e)
    b( fis' b fis) fis,( cis' fis cis)\break
    g( d' g d) d,( a' d a)
    g( d' g d) a( e' a e)
    d( a' d a) a,( e' a e)
    b( fis' b fis) fis,( cis' fis cis)
    g( d' g d) d,( a' d a)
    g( d' g d) a( e' a e)
    d( a' d a) a,( e' a e) 
    b( fis' a fis) fis,( cis' fis cis) 
    g( d' g d) d,( a' d a)
    g( d' g d) a( e' a cis)
    d,16( a' d fis d a d, a') a,( e' a cis a e a, e')
    b( fis' b d b fis b, fis') fis,( cis' fis a fis cis fis, cis')
    g( d'g b g d g, d') d,( a' d fis d a d, a')
    g( d' g b g d g, d') a(e' a cis a e a, e')
    d( a' d fis d a d, a') a,( e' a cis a e a, e')
    b( fis' b d b fis b, fis') fis,( cis' fis a fis cis fis, cis')
    g( d' g b g d g, d') d,( a' d fis d a d, a')
    g( d' g b g d g, d') a( e' a cis a e a, e')
    d( a' d fis d a d, a') a,( e' a cis a e a, e')
    b( fis' b d b fis b, fis') fis,( cis' fis a fis cis fis, cis')
    g( d' g b g d g, d') d,( a' d fis d a d, a') 
    g( d' g b g d g, d') a( e' a cis a e a, e')
    d( a' d e d a d, a') a,( e' a cis a e a, e')
    b( fis' b d b fis b, fis') a,( cis fis a fis cis fis, cis')
    g( d' g b g d g, d') d,( a' d fis d a d, a')
    g( d' g b g d g, d') a( e' a cis a e a, e')
    d( a' d fis d a d, a') a,( e' a cis a e a, e')
    b( fis' b d b fis b, fis') fis,( cis' fis a fis cis fis, cis')
    g( d' g b g d g, d') d,( a' d fis d a d, a') 
    g( d' g b g d g, d') a( e' a cis a e a, e)
    d8( a' d fis \clef "treble" a d fis a
    d8 fis a4) d,2\fermata

  }
  >>
}

