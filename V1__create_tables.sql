create table users
(
    id       serial primary key,
    username text UNIQUE,
    password text,
    email    text UNIQUE,
    bio      text,
    image    text
);

create table articles
(
    id          serial primary key,
    user_id     integer references users,
    slug        text UNIQUE,
    title       text,
    description text,
    body        text,
    tagList     text[],
    created_at  TIMESTAMP NOT NULL,
    updated_at  TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

create table article_favorites
(
    article_id integer not null references articles,
    user_id    integer not null references users,
    primary key (article_id, user_id)
);

create table follows
(
    user_id   integer not null references users,
    follow_id integer not null references users
);

create table comments
(
    id         serial primary key,
    body       text,
    article_id integer references articles,
    user_id    integer references users,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);