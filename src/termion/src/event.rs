//! Mouse and key events.

use std::io::{Error, ErrorKind};
use std::ascii::AsciiExt;
use std::str;
use std::fmt;

/// An event reported by the terminal.
#[derive(Debug, Copy, Clone, PartialEq, Eq, Hash)]
pub enum Event {
    ///En A keyboard key press
    ///De Eine Tastaturtaste Druck
    ///Fr Appui d'une touche de clavier
    Key(Key),
    ///En A mouse button press, release or wheel use at specific coordinates.
    ///De Eine Mousetaste Druck
    ///Fr Appui d'une touche de clavier
    Mouse(MouseEvent),
    ///En An event that cannot currently be evaluated.
    ///De Eine Tastaturtaste Druck
    ///Fr Appui d'une touche de clavier
    Unsupported,
}

/// A mouse related event.
#[derive(Debug, Copy, Clone, PartialEq, Eq, Hash)]
pub enum MouseEvent {
    ///En A mouse button was pressed, the coordinates are one-based
    ///De Ein Mousetaste gedrückt ist
    ///Fr Un bouton de souris est appuyé
    Press(MouseButton, u16, u16),

    ///En A mouse button was released, the coordinates are one-based
    ///De Ein Mousetaste losgelassen ist
    ///Fr Un bouton de souris est relâché
    Release(u16, u16),

    ///En A mouse button is held down, the coordinates are one-based
    ///De Ein Mousetaste gedrückt gehalten ist
    ///Fr Un bouton de souris est maintenu appuyé
    Drag(MouseButton, u16, u16),
}

/// A mouse button.
#[derive(Debug, Copy, Clone, PartialEq, Eq, Hash)]
pub enum MouseButton {

    /*  ****  CLICK ONLY  ****  */

    ///En The left mouse button is pressed
    ///De Die Linksmousetaste ist gedrückt
    ///Fr Le bouton gauche de la souris est appuyé
    Left,

    ///En The right mouse button is pressed
    ///De Die Rechtsmousetaste ist gedrückt
    ///Fr Le bouton droit de la souris est appuyé
    Right,

    ///En The mouse wheel button is pressed
    ///De Das Mausradtaste ist gedrückt
    ///Fr Le bouton molette de la souris est appuyé
    Wheel,

    ///En The mouse wheel is going up
    ///De Die Mousrad geht nach oben
    ///Fr La molette est tournée vers le haut
    WheelUp,

    ///En The mouse wheel is going down
    ///De Die Mouserad geht nach unten
    ///Fr La molette est tournée vers le bas
    WheelDown,


    /*  **********  AJOUTS D'EVENEMENTS **********  */


    /*  ****  DRAG ONLY  ****  */

    ///En The left mouse button is held while moving pointer
    ///De Die Linksmousetaste ist gehalten, wenn der Mauszeiger bewegt
    ///Fr Le bouton gauche de la souris est maintenu en déplaçant le pointeur
    LeftDrag,

    ///En The wheel mouse button is held while moving pointer
    ///De Die Mouseradtaste ist gehalten, wenn der Mauszeiger bewegt
    ///Fr Le bouton molette est maintenu en déplaçant le pointeur
    WheelDrag,

    ///En The right mouse button is held while moving pointer
    ///De Die Rechtsmousetaste ist gehalten, wenn der Mauszeiger bewegt
    ///Fr Le bouton droit de la souris est maintenu en déplaçant le pointeur
    RightDrag,

    /*  ****  SHIFT CLICK  ****  */

    ///En The left mouse button is pressed while helding Shift
    ///De Die Linksmousetaste ist gedrückt, wenn Shift gehalten ist
    ///Fr Le bouton gauche de la souris est appuyé quand Shift est maintenu
    ShiftLeft,

    ///En The wheel mouse button is pressed while helding Shift
    ///De Die Mouseradtaste ist gedrückt, wenn Shift gehalten ist
    ///Fr Le bouton molette est appuyé quand Shift est maintenu
    ShiftWheel,

    ///En The right mouse button is pressed while helding Shift
    ///De Die Rechtsmousetaste ist gedrückt, wenn Shift gehalten ist
    ///Fr Le bouton droit de la souris est appuyé quand Shift est maintenu
    ShiftRight,

    /*  *****  SHIFT DRAG   *****  */

    ///En The left mouse button and Shift are held while moving pointer
    ///De Die Linksmousetaste und Shift sind gehalten, wenn der Mauszeiger
    ///De bewegt
    ///Fr Le bouton gauche de la souris et Shift sont maintenus en déplaçant
    ///Fr le pointeur
    ShiftLeftDrag,

    ///En The wheel mouse button and Shift are held while moving pointer
    ///De Die Mouseradtaste und Shift sind gehalten, wenn der Mauszeiger bewegt
    ///Fr Le bouton molette et Shift sont maintenus en déplaçant le pointeur
    ShiftWheelDrag,

    ///En The right mouse button and Shift are held while moving pointer
    ///De Die Rechtsmousetaste und Shift sind gehalten, wenn der Mauszeiger 
    ///De bewegt
    ///Fr Le bouton droit de la souris et Shift sont maintenu en déplaçant
    ///Fr le pointeur
    ShiftRightDrag,

    /*  ****  CTRL CLICK  ****  */

    ///En The left mouse button is pressed while helding Ctrl
    ///De Die Linksmousetaste ist gedrückt, wenn Ctrl gehalten ist
    ///Fr Le bouton gauche de la souris est appuyé quand Ctrl est maintenu
    CtrlLeft,

    ///En The wheel mouse button is pressed while helding Ctrl
    ///De Die Mouseradtaste ist gedrückt, wenn Ctrl gehalten ist
    ///Fr Le bouton molette est appuyé quand Ctrl est maintenu
    CtrlWheel,

    ///En The right mouse button is pressed while helding Ctrl 
    ///De Die Rechtsmousetaste ist gedrückt, wenn Ctrl gehalten ist
    ///Fr Le bouton droit de la souris est appuyé quand Ctrl est maintenu
    CtrlRight,

    ///En The mouse wheel is going up while helding Ctrl 
    ///De Die Mousrad geht nach oben, wenn Ctrl gehalten ist
    ///Fr La molette est tournée vers le haut quand Ctrl est maintenu
    CtrlWheelUp,

    ///En The mouse wheel is going down while helding Ctrl 
    ///De Die Mousrad geht nach unten, wenn Ctrl gehalten ist
    ///Fr La molette est tournée vers le bas quand Ctrl est maintenu
    CtrlWheelDown,

    /*  *****  CTRL DRAG  *****  */

    ///En The left mouse button and Ctrl are held while moving pointer
    ///De Die Linksmousetaste und Ctrl sind gehalten, wenn der Mauszeiger bewegt
    ///Fr Le bouton gauche de la souris et Ctrl sont maintenus en déplaçant
    ///Fr le pointeur
    CtrlLeftDrag,

    ///En The wheel mouse button and Ctrl are held while moving pointer
    ///De Die Mouseradtaste und Ctrl sind gehalten, wenn der Mauszeiger bewegt
    ///Fr Le bouton molette et Ctrl sont maintenus en déplaçant le pointeur
    CtrlWheelDrag,

    ///En The right mouse button and Ctrl are held while moving pointer
    ///De Die Rechtsmousetaste und Ctrl sind gehalten, wenn der Mauszeiger
    ///De bewegt
    ///Fr Le bouton droit de la souris et Ctrl sont maintenu en déplaçant
    ///Fr le pointeur
    CtrlRightDrag,

    /*  ** CTRL SHIFT CLICK **  */

    ///En The left mouse button is pressed while Ctrl and Shift are held
    ///De Die Linksmousetaste ist gedrückt, wenn Ctrl und Shift gehalten sind
    ///Fr Le bouton gauche de la souris est appuyé quand Ctrl et Shift
    ///Fr sont maintenus
    ShiftCtrlLeft,

    ///En The wheel mouse button is pressed while Ctrl and Shift are held
    ///De Die Mouseradtaste ist gedrückt, wenn Ctrl und Shift gehalten sind
    ///Fr Le bouton molette est appuyé quand Ctrl et Shift sont maintenus
    ShiftCtrlWheel,

    ///En The right mouse button is pressed while Ctrl and Shift are held
    ///De Die Rechtsmousetaste ist gedrückt, wenn Ctrl und Shift gehalten sind
    ///Fr Le bouton droit de la souris est appuyé quand Ctrl et Shift
    ///Fr sont maintenus
    ShiftCtrlRight,

    /*  *** CTRL SHIFT DRAG ***  */

    ///En The left mouse button, Ctrl and Shift are held while moving pointer
    ///De Die Linksmousetaste, Ctrl und Shift sind gehalten, wenn der
    ///De Mauszeiger bewegt
    ///Fr Le bouton gauche de la souris, Ctrl et Shift sont maintenus 
    ///Fr en déplaçant le pointeur
    ShiftCtrlLeftDrag,

    ///En The wheel mouse button, Ctrl and Shift are held while moving pointer
    ///De Die Mouseradtaste, Ctrl und Shift sind gehalten, wenn der
    ///De Mauszeiger bewegt
    ///Fr Le bouton molette, Ctrl et Shift sont maintenus en déplaçant 
    ///Fr le pointeur
    ShiftCtrlWheelDrag,

    ///En The right mouse button, Ctrl and Shift are held while moving pointer
    ///De Die Rechtsmousetaste, Ctrl und Shift sind gehalten, wenn der
    ///De Mauszeiger bewegt
    ///Fr Le bouton droit de la souris, Ctrl et Shift sont maintenu en déplaçant
    ///Fr le pointeur
    ShiftCtrlRightDrag,


    /*  **********  AJOUTS D'EVENEMENTS **********  */
}

/// A key.
#[derive(Debug, Copy, Clone, PartialEq, Eq, Hash)]
pub enum Key {
    /// Backspace.
    Backspace,
    /// Left arrow.
    Left,
    /// Right arrow.
    Right,
    /// Up arrow.
    Up,
    /// Down arrow.
    Down,
    /// Home key.
    Home,
    /// End key.
    End,
    /// Page Up key.
    PageUp,
    /// Page Down key.
    PageDown,
    /// Delete key.
    Delete,
    /// Insert key.
    Insert,
    /// Function keys.
    ///
    /// Only function keys 1 through 12 are supported.
    F(u8),
    /// Normal character.
    Char(char),
    /// Alt modified character.
    Alt(char),
    /// Ctrl modified character.
    ///
    /// Note that certain keys may not be modifiable with `ctrl`, due to limitations of terminals.
    Ctrl(char),
    /// Null byte.
    Null,

    #[allow(missing_docs)]
    #[doc(hidden)]
    __IsNotComplete
}

impl fmt::Display for Key
{ fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result
      { write!(f, "{}", self) }}

/// Parse an Event from `item` and possibly subsequent bytes through `iter`.
pub fn parse_event<I>(item: Result<u8, Error>, iter: &mut I) -> Result<Event, Error>
where I: Iterator<Item = Result<u8, Error>>
{
    let error = Err(Error::new(ErrorKind::Other, "Could not parse an event"));
    match item {
        Ok(b'\x1B') => {
            Ok(match iter.next() {
                Some(Ok(b'O')) => {
                    match iter.next() {
                        Some(Ok(val @ b'P' ... b'S')) => Event::Key(Key::F(1 + val - b'P')),
                        _ => return error,
                    }
                }
                Some(Ok(b'[')) => {
                    match iter.next() {
                        Some(Ok(b'D')) => Event::Key(Key::Left),
                        Some(Ok(b'C')) => Event::Key(Key::Right),
                        Some(Ok(b'A')) => Event::Key(Key::Up),
                        Some(Ok(b'B')) => Event::Key(Key::Down),
                        Some(Ok(b'H')) => Event::Key(Key::Home),
                        Some(Ok(b'F')) => Event::Key(Key::End),
                        Some(Ok(b'M')) => {
                            // X10 emulation mouse encoding: ESC [ CB Cx Cy (6 characters only).
                            let cb = iter.next().unwrap().unwrap() as i8 - 32;
                            // (1, 1) are the coords for upper left.
                            let cx = (iter.next().unwrap().unwrap() as u8).saturating_sub(32) as u16;
                            let cy = (iter.next().unwrap().unwrap() as u8).saturating_sub(32) as u16;
                            Event::Mouse(match cb & 0b11 {
                                0 => {
                                    if cb & 0x40 != 0 {
                                        MouseEvent::Press(MouseButton::WheelUp, cx, cy)
                                    } else {
                                        MouseEvent::Press(MouseButton::Left, cx, cy)
                                    }
                                }
                                1 => {
                                    if cb & 0x40 != 0 {
                                        MouseEvent::Press(MouseButton::WheelDown, cx, cy)
                                    } else {
                                        MouseEvent::Press(MouseButton::Wheel, cx, cy)
                                    }
                                }
                                2 => MouseEvent::Press(MouseButton::Right, cx, cy),
                                3 => MouseEvent::Release(cx, cy),
                                _ => return error,
                            })
                        }
                        Some(Ok(b'<')) => {
                            // xterm mouse encoding:
                            // ESC [ < Cb ; Cx ; Cy ; (M or m)
                            let mut buf = Vec::new();
                            let mut c = iter.next().unwrap().unwrap();
                                while match c {
                                    b'm' | b'M' => false,
                                    _ => true,
                                } {
                                    buf.push(c);
                                    c = iter.next().unwrap().unwrap();
                                }
                            let str_buf = String::from_utf8(buf).unwrap();
                            let ref mut nums = str_buf.split(';');

                            let cb = nums.next().unwrap().parse::<u16>().unwrap();
                            let cx = nums.next().unwrap().parse::<u16>().unwrap();
                            let cy = nums.next().unwrap().parse::<u16>().unwrap();

                            let button = match cb {

                                ///Click
                                0 => MouseButton::Left,
                                1 => MouseButton::Wheel,
                                2 => MouseButton::Right,
                                64 => MouseButton::WheelUp,
                                65 => MouseButton::WheelDown,

                            /*  **********  AJOUTS D'EVENEMENTS **********  */

                                ///Drag
                                32 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::LeftDrag, cx, cy))) ,
                                33 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::WheelDrag, cx, cy))) ,
                                34 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::RightDrag, cx, cy))) ,

                                ///Shift Click
                                4 => MouseButton::ShiftLeft,
                                5 => MouseButton::ShiftWheel,
                                6 => MouseButton::ShiftRight,

                                ///Shift Drag
                                36 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::ShiftLeftDrag, cx, cy))) ,
                                37 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::ShiftWheelDrag, cx, cy))) ,
                                38 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::ShiftRightDrag, cx, cy))) ,

                                ///Control Click
                                16 => MouseButton::CtrlLeft,
                                17 => MouseButton::CtrlWheel,
                                18 => MouseButton::CtrlRight,
                                80 => MouseButton::CtrlWheelUp,
                                81 => MouseButton::CtrlWheelDown,

                                ///Control Drag
                                48 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::CtrlLeftDrag, cx, cy))) ,
                                49 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::CtrlWheelDrag, cx, cy))) ,
                                50 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::CtrlRightDrag, cx, cy))) ,

                                ///Control Shift Click
                                20 => MouseButton::ShiftCtrlLeft,
                                21 => MouseButton::ShiftCtrlWheel,
                                22 => MouseButton::ShiftCtrlRight,

                                ///Control Shift Drag
                                52 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::ShiftCtrlLeftDrag, cx, cy))) ,
                                53 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::ShiftCtrlWheelDrag, cx, cy))) ,
                                54 => return Ok(Event::Mouse(MouseEvent::Drag(MouseButton::ShiftCtrlRightDrag, cx, cy))) ,

                            /*  **********  AJOUTS D'EVENEMENTS **********  */

                                _ => return error,
                            };
                            Event::Mouse(match c {
                                b'M' => MouseEvent::Press(button, cx, cy),
                                b'm' => MouseEvent::Release(cx, cy),
                                _ => return error,
                            })
                        }
                        Some(Ok(c @ b'0'...b'9')) => {
                            // Numbered escape code.
                            let mut buf = Vec::new();
                            buf.push(c);
                            let mut c = iter.next().unwrap().unwrap();
                            while match c {
                                b'M' | b'~' => false,
                                _ => true,
                            } {
                                buf.push(c);
                                c = iter.next().unwrap().unwrap();
                            }

                            match c {
                                // rxvt mouse encoding:
                                // ESC [ Cb ; Cx ; Cy ; M
                                b'M' => {
                                    let str_buf = String::from_utf8(buf).unwrap();
                                    let ref mut nums = str_buf.split(';');

                                    let cb = nums.next().unwrap().parse::<u16>().unwrap();
                                    let cx = nums.next().unwrap().parse::<u16>().unwrap();
                                    let cy = nums.next().unwrap().parse::<u16>().unwrap();

                                    let event = match cb {
                                        32 => MouseEvent::Press(MouseButton::Left, cx, cy),
                                        33 => MouseEvent::Press(MouseButton::Wheel, cx, cy),
                                        34 => MouseEvent::Press(MouseButton::Right, cx, cy),
                                        35 => MouseEvent::Release(cx, cy),
                                        96 => MouseEvent::Press(MouseButton::WheelUp, cx, cy),
                                        97 => MouseEvent::Press(MouseButton::WheelUp, cx, cy),
                                        _ => return error,
                                    };

                                    Event::Mouse(event)
                                },
                                // Special key code.
                                b'~' => {
                                    let num: u8 = String::from_utf8(buf).unwrap().parse().unwrap();
                                    match num {
                                        1 | 7 => Event::Key(Key::Home),
                                        2 => Event::Key(Key::Insert),
                                        3 => Event::Key(Key::Delete),
                                        4 | 8 => Event::Key(Key::End),
                                        5 => Event::Key(Key::PageUp),
                                        6 => Event::Key(Key::PageDown),
                                        v @ 11...15 => Event::Key(Key::F(v - 10)),
                                        v @ 17...21 => Event::Key(Key::F(v - 11)),
                                        v @ 23...24 => Event::Key(Key::F(v - 12)),
                                        _ => return error,
                                    }
                                }
                                _ => return error,
                            }
                        }
                        _ => return error,
                    }
                }
                Some(Ok(c)) => {
                    let ch = parse_utf8_char(c, iter);
                    Event::Key(Key::Alt(try!(ch)))
                }
                Some(Err(_)) | None => return error,
            })
        }
        Ok(b'\n') | Ok(b'\r') => Ok(Event::Key(Key::Char('\n'))),
        Ok(b'\t') => Ok(Event::Key(Key::Char('\t'))),
        Ok(b'\x7F') => Ok(Event::Key(Key::Backspace)),
        Ok(c @ b'\x01'...b'\x1A') => Ok(Event::Key(Key::Ctrl((c as u8 - 0x1 + b'a') as char))),
        Ok(c @ b'\x1C'...b'\x1F') => {
            Ok(Event::Key(Key::Ctrl((c as u8 - 0x1C + b'4') as char)))
        }
        Ok(b'\0') => Ok(Event::Key(Key::Null)),
        Ok(c) => {
            Ok({
                let ch = parse_utf8_char(c, iter);
                Event::Key(Key::Char(try!(ch)))
            })
        }
        Err(e) => Err(e),
    }
}

/// Parse `c` as either a single byte ASCII char or a variable size UTF-8 char.
fn parse_utf8_char<I>(c: u8, iter: &mut I) -> Result<char, Error>
    where I: Iterator<Item = Result<u8, Error>> {
    let error = Err(Error::new(ErrorKind::Other, "Input character is not valid UTF-8"));
    if c.is_ascii() {
        Ok(c as char)
    } else {
        let ref mut bytes = Vec::new();
        bytes.push(c);

        loop {
            bytes.push(iter.next().unwrap().unwrap());
            match str::from_utf8(bytes) {
                Ok(st) => return Ok(st.chars().next().unwrap()),
                Err(_) => {},
            }
            if bytes.len() >= 4 { return error; }
        }
    }
}

#[cfg(test)]
#[test]
fn test_parse_utf8() {
    let st = "abcéŷ¤£€ù%323";
    let ref mut bytes = st.bytes().map(|x| Ok(x));
    let chars = st.chars();
    for c in chars {
        let b = bytes.next().unwrap().unwrap();
        assert!(c == parse_utf8_char(b, bytes).unwrap());
    }
}
