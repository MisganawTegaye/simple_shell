#include "shell.h"

/**
 * myhistory - Displays the history list, one command per line,
 *             preceded with line numbers starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Unsets an alias from the alias list.
 * @info: Parameter struct.
 * @alias_str: The alias string to unset.
 *
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *alias_str)
{
	char *equal_sign, tmp;
	int ret;

	equal_sign = _strchr(alias_str, '=');
	if (!equal_sign)
		return (1);

	tmp = *equal_sign;
	*equal_sign = '\0';

	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, alias_str, -1)));

	*equal_sign = tmp;
	return (ret);
}

/**
 * set_alias - Sets an alias in the alias list.
 * @info: Parameter struct.
 * @alias_str: The alias string to set.
 *
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *alias_str)
{
	char *equal_sign;

	equal_sign = _strchr(alias_str, '=');
	if (!equal_sign)
		return (1);

	if (!*++equal_sign)
		return (unset_alias(info, alias_str));

	unset_alias(info, alias_str);
	return (add_node_end(&(info->alias), alias_str, 0) == NULL);
}

/**
 * print_alias - Prints an alias string.
 * @node: The alias node.
 *
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *equal_sign, *alias;

	if (node)
	{
		equal_sign = _strchr(node->str, '=');
		for (alias = node->str; alias <= equal_sign; alias++)
			_putchar(*alias);
		_putchar('\'');
		_puts(equal_sign + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * myalias - Mimics the alias builtin (man alias).
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int myalias(info_t *info)
{
	int i = 0;
	char *equal_sign;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		equal_sign = _strchr(info->argv[i], '=');
		if (equal_sign)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

