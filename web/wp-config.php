<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * Localized language
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'wpuser' );

/** Database password */
define( 'DB_PASSWORD', 'password' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',          '%q_5EuF1Xr<7A<Y0U5HvI2_/~:U:^TwI!_|ELR[N)WW rX)DZ?r/#Flr%U(XetTS' );
define( 'SECURE_AUTH_KEY',   'D;p</aqX =@wY4fKM59X61m9j+.Mxdss`$/?>V}W~mbagvog?wp{qDhmI(!{j>$}' );
define( 'LOGGED_IN_KEY',     'Pmr6]:kPnB6dr? N3?Q__aI/n_I]ILy#P(PC%s1c6>D^^V!YH(Se&r<+mr1Ubtgb' );
define( 'NONCE_KEY',         '^4MKe(D>7g::z(K;!H14WiK}3^ dh5M)WC:yULZNf1Cer2zB l#k9XP&:?(,jj`d' );
define( 'AUTH_SALT',         'BEPiEV?=EUaE]<](4Y3CPRWsx}yrk/hVyOsNZZW+QR+4s-YKQGPG0wE(kbTD@O$+' );
define( 'SECURE_AUTH_SALT',  'M{frb-J5vWX7xqD.ej`bwS^WpM+&PWKh/c>t(K.gSxB$e~k`5u-1C~H`K2/:cjXJ' );
define( 'LOGGED_IN_SALT',    '=GhyNMxhNuKz)B/&-U,=Q42[?DHhE7Dl{fU98O3FOb%/pRE(=J==ge6NDI eaFHn' );
define( 'NONCE_SALT',        'UJKd~]8nw%?h. a,ih,~}lBail!2SbK?0i|M,+_%P@8kb[ZXN2S Qy[tnI<|r>,(' );
define( 'WP_CACHE_KEY_SALT', '/Ht:]Wmo|NKi64.#f7P#WOh-YaN2f^HjF9#Cc&9ppYAhc&8u{Wr=B>%tr*BiX1O)' );


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';


/* Add any custom values between this line and the "stop editing" line. */



/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
if ( ! defined( 'WP_DEBUG' ) ) {
	define( 'WP_DEBUG', false );
}

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
