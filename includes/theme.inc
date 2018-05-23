<?php



/**
 * Implements theme_suggestions_taxonomy_term_alter()
 *
 * @param $suggestions
 * @param $variables
 */
function base_theme_suggestions_taxonomy_term_alter(array &$suggestions, array $variables) {
  $suggestions[] = 'taxonomy_term__' .$variables['elements']['name']['#bundle'] . '__' . $variables['elements']['#view_mode'];
}


/**
 * Implements hook_theme_suggestions_block_alter().
 */
function base_theme_suggestions_block_alter(array &$suggestions, array $variables, $hook){
  if (!empty($variables['elements']['content']['#block_content'])) {
    //creates template theme suggestion for custom block type
    array_splice($suggestions, 1, 0, 'block__bundle__' . $variables['elements']['content']['#block_content']->bundle());
    // Get bundle/block type.
  }
}

/**
 * Implements hook_theme_suggestions_block_alter().
 */
 //Adding the media url to the variables
function base_preprocess_media(&$variables) {
  $variables['url'] = $variables['media']->toUrl();
}

 //Adding the users url to the variables
function base_preprocess_user(&$variables) {
  $variables['user_link'] = $variables['user']->toUrl();
}


/**
 * Implements hook_theme_suggestions_user_alter().
 *
 */
function base_theme_suggestions_user_alter(&$suggestions, $vars, $hook) {

  // Define the view mode.
  $mode = $vars['elements']['#view_mode'];

  // Create a theme hook suggestion which has the view mode name in it.
  $suggestions[] = 'user__' . $mode;
}
