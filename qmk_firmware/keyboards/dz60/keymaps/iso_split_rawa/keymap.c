// using as reference
// https://docs.qmk.fm/#/keymap

// thanks to atlacat, hailbreno, itsaferbie and weeheavy...

#include QMK_KEYBOARD_H

/*
* Each layer gets a name for readability.
* The underscores don't mean anything - you can
* have a layer called STUFF or any other name.
* Layer names don't all need to be of the same
* length, and you can also skip them entirely
* and just use numbers.
*
*/
#define BL 0     // Base Layer
#define FL 1     // Function Layer
#define EL 2     // Easy access Layer
#define GL 3     // Gaming Layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * 	1      2     3     4    5     6      7     8     9    10     11  12   13    14
 * 	ESC,   1,    2,    3,   4,    5,     6,    7,    8,   9,     0,  +,   ´,    BSPC,
 *  TAB,   Q,    W,    E,   R,    T,     Y,    U,    I,   O,     P,  Å,   ¨,
 *  CAPS,  A,    S,    D,   F,    G,     H,    J,    K,   L,     ö,  ä,   ',    ENT,
 *  LSFT,  <,    Z,    X,   C,    V,     B,    N,    M,   ,,     .,  -,   RSFT,
 *  LCTRL, LGUI, LALT, SPC, MODE, BCSPC, RALT, RGUI, APP, RCTL),
 */

  /* Keymap BL: Base Layer (Default Layer)
   *
   * ,-----------------------------------------------------------.
   * | ' | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |Backsp |
   * |-----------------------------------------------------------|
   * | Tab | q | w | e | r | t | y | u | i | o | p | [ | ] |enter|
   * |------------------------------------------------------     |
   * | Caps  | a | s | d | f | g | h | j | k | l | ; | ' | # |   |
   * |-----------------------------------------------------------|
   * |Shft| < | z | x | c | v | b | n | m | , | . | / |  Shift   |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt | Space  | FN |  Space  |Alt |Gui | NL |Ctrl |
   * `-----------------------------------------------------------'
   */
   [BL] = LAYOUT_60_iso_split(
	//  1               2          3          4          5          6          7          8          9          10         11         12         13         14
	    KC_ESC,         KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,
      KC_TAB ,        KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,
      KC_CAPS,        KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,   KC_NUHS,   KC_ENT,
      KC_LSFT,        KC_NUBS,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
      KC_LCTL,        KC_LGUI,   KC_LALT,   KC_SPC,    MO(FL),    KC_BSPC,   KC_RALT,   KC_RGUI,   KC_APP,    KC_RCTL),

  /* Keymap FL: Function Layer
   *
   * ,-----------------------------------------------------------.
   * |ESC|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  DEL  |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |prt|   |   |     |
   * |------------------------------------------------------     |
   * |       |m l|m d|m u|m r|   |   | l | d | u | r |   |   |   |
   * |-----------------------------------------------------------|
   * |    |   |   |   |   |mb1|mb2|   |hm |pgd|pgu|end|          |
   * |-----------------------------------------------------------|
   * |    |    |    |        |    |         |    |    |    |     |
   * `-----------------------------------------------------------'
   */
   [FL] = LAYOUT_60_iso_split(
	//  1          2            3           4             5          6          7          8          9          10         11         12         13         14
	    KC_GRV,    KC_F1,       KC_F2,      KC_F3,        KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_DEL,
      _______,   _______,     KC_PGUP,    _______,      _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
      _______,   KC_HOME,     KC_PGDN,    KC_END,       _______,   _______,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  _______,   _______,   _______,   _______,
      _______,   _______,     _______,    _______,      _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
      _______,   _______,     _______,    _______,      _______,   TG(GL),   _______,   _______,   _______,   _______),

  /* Keymap NL: Numpad Layer
  *
  */
   [EL] = LAYOUT_60_iso_split(
	//  1          2          3          4          5          6          7           8           9             10                 11               12         13         14
	    _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,     _______,     _______,           _______,         _______,   _______,    _______,
      _______,   _______,   _______,   _______,   _______,   _______,   _______,    RALT(KC_7),  RALT(KC_0),  _______,           _______,         _______,   _______,
      _______,   _______,   _______,   _______,   _______,   _______,   LSFT(KC_7), LSFT(KC_8),  LSFT(KC_9),  RALT(KC_MINS),     _______,         _______,   _______,    _______,
      _______,   _______,   _______,   _______,   _______,   _______,   _______,    KC_NUBS,     RALT(KC_8),  RALT(KC_9),        LSFT(KC_NUBS),   _______,   _______,
      _______,   _______,   _______,   _______,   _______,    _______,   _______,    _______,     _______,     _______),

   [GL] = LAYOUT_60_iso_split(
	//  1          2            3           4             5          6          7          8          9          10         11         12         13         14
	    KC_I,      _______,     _______,    _______,      _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   TG(GL),
      _______,   _______,     _______,    _______,      _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
      KC_J,      _______,     _______,    _______,      _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
      _______,   _______,     _______,    _______,      _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
      _______,   _______,     _______,    _______,      KC_K,      KC_BSPC,    _______,   _______,   _______,   _______),
};

